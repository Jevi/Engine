#ifndef ENGINE_H
#define ENGINE_H

#define NO_SDL_GLEXT
#include <GL/glew.h>
#include <Box2D/Box2D.h>

#ifdef _WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <direct.h>
#define getcwd _getcwd
#else
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#include <unistd.h>
#endif

#include "graphics.h"
#include "debug.h"
#include "event_handler.h"
#include "asset_system.h"
#include "level_system.h"

using namespace std;

class AssetLoader;
class LevelSystem;

class Engine: public EventHandler
{
public:

	static string GetProject()
	{
		return appProject;
	}

	static b2World* GetWorld()
	{
		if (!world)
		{
			world = new b2World(b2Vec2(0.0f, 9.81f));
		}
		return world;
	}
	/*
	 Returns singleton Engine instance.
	 */
	static Engine* GetInstance();
	/*
	 Initializes engine and begins main game loop (heartbeat)
	 */
	void Start();
	/*
	 Polls events for Engine to utilize
	 */
	void OnEvent(SDL_Event* Event);
	/*
	 Handles Engine specific input logic on a key press
	 */
	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	/*
	 Handles Engine specific input logic based on keyboard state
	 */
	void OnKeyboardState(Uint8* keyboardState);

private:

	Engine();

	enum AppState
	{
		Uninitialized, Running, Exiting
	};

	static Engine* instance;
	static b2World* world;

	int appWidth;
	int appHeight;
	static string appProject;

	AppState appState;
	SDL_Surface* appWindow;
	SDL_Event appEvent;

	AssetLoader* assetLoader;
	LevelSystem* levelManager;

	/*
	 Initializes SDL/OpenGL as well as any other vital objects
	 */
	bool Init();
	/*
	 Engine Heartbeat. Engine core logic depending on state.
	 */
	void Heartbeat();
	/*
	 Update
	 */
	void Update();
	/*
	 Renders all render-able assets/entities
	 */
	void Render();

	bool IsExiting();

	/*
	 Changes the Engine's state
	 */
	void SwitchState(AppState state);

	string ToString(AppState state);
	/*
	 Changes Engine state to AppState::Exiting
	 */
	void Exit();
	/*
	 Frees up memory, deletes instance and quits APIs accordingly
	 */
	void Destroy();

};

#endif

