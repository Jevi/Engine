#ifndef ENGINE_H
#define ENGINE_H

#define NO_SDL_GLEXT
#include <GL/glew.h>

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
#include "entity.h"
#include "asset_loader.h"
#include "level_manager.h"

using namespace std;

class AssetLoader;
class LevelManager;

class Engine: public EventHandler
{
public:

	static string GetProject()
	{
		return appProject;
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
	int appWidth;
	int appHeight;
	static string appProject;

	AppState appState;
	SDL_Surface* appWindow;
	SDL_Event appEvent;

	AssetLoader* assetLoader;
	LevelManager* levelManager;

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

