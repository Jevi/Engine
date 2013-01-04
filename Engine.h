#ifndef ENGINE_H
#define ENGINE_H

#define NO_SDL_GLEXT
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

#include "Graphics.h"
#include "Debug.h"
#include "EventHandler.h"
#include "Entity.h"
#include "EntityManager.h"

class Engine: public EventHandler
{
public:

	Engine();
	~Engine();

	int appWidth;
	int appHeight;

	void OnStart();

	virtual void OnEvent(SDL_Event* Event)
	override;
	virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
	override;
	virtual void OnExit()
	override;

private:

	bool OnInit();
	void OnLoop();

	void OnUpdate();
	void OnRender();
	bool IsExiting();

	enum AppState
	{
		Uninitialized, Running, Exiting
	};

	void SwitchState(AppState state);
	const char* ToString(AppState state);

	AppState appState;
	SDL_Surface* appWindow;
	SDL_Event appEvent;

	EntityManager entityManager;
};

#endif

