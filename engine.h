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
#include "asset_manager.h"

class Engine: public EventHandler
{
public:

	static Engine* GetInstance();

	void OnStart();
	void OnEvent(SDL_Event* Event);
	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	void OnExit();
	void Destroy();

private:

	Engine();

	enum AppState
	{
		Uninitialized, Running, Exiting
	};

	static Engine* instance;
	int appWidth;
	int appHeight;

	AppState appState;
	SDL_Surface* appWindow;
	SDL_Event appEvent;

	void SwitchState(AppState state);
	const char* ToString(AppState state);
	bool OnInit();
	void OnLoop();

	void OnUpdate();
	void OnRender();
	bool IsExiting();

};

#endif

