#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

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

#include "event_handler.h"

class Engine: public EventHandler {
public:

	/*
	 Returns singleton Engine instance.
	 */
	static Engine* GetInstance() {
		if (!instance) {
			instance = new Engine;
		}
		return instance;
	}
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

	// Accessors

	b2World* GetWorld() {
		return world;
	}

	std::string GetAppProject() {
		return appProject;
	}

	int GetAppHeight() {
		return appHeight;
	}

	int GetAppWidth() {
		return appWidth;
	}

	std::string GetAppState() {
		return ToString(appState);
	}

private:

	Engine();
	~Engine() {
	}

	enum AppState {
		Uninitialized, Running, Exiting
	};

	static Engine* instance;
	b2World* world;

	int appWidth;
	int appHeight;
	std::string appProject;

	AppState appState;
	SDL_Surface* appWindow;
	SDL_Event appEvent;

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

	std::string ToString(AppState state);
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

