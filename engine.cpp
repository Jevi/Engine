#include "engine.h"

Engine* Engine::instance;
EntityLoader* el;

Engine::Engine() :
		appState(Uninitialized), appWidth(640), appHeight(480)
{

}

Engine* Engine::GetInstance()
{
	if (instance != NULL)
	{
		return instance;
	}

	instance = new Engine;
	return instance;
}

void Engine::Destroy()
{
	el->Destroy();
	Debug::Log("Exiting Engine");
	SDL_Quit();
	delete this;
}

void Engine::OnStart()
{
	if (appState != Uninitialized)
	{
		return;
	}

	if (OnInit())
	{
		appState = Running;
		while (!IsExiting())
		{
			OnLoop();
		}
	}
	Destroy();
}

bool Engine::OnInit()
{
	char currentDirectory[FILENAME_MAX];
	_getcwd(currentDirectory, sizeof(currentDirectory));
	Debug::Log("Current Directory: %s", currentDirectory);

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		Debug::Log("Could Not Initialize SDL");
		return false;
	}
	Debug::Log("SDL Initialized");

	SDL_WM_SetCaption("SDL OPENGL ENGINE", NULL);

	if ((appWindow = SDL_SetVideoMode(appWidth, appHeight, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
	{
		Debug::Log("Could Not Set SDL Video Mode");
		return false;
	}
	Debug::Log("SDL Video Mode Initialized");

	el = EntityLoader::GetInstance();
	el->LoadAssetsFromXML("res\\test.xml");
	el->SetCurrentScene(1);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, appWidth, appHeight, 0, 1, -1);

	return true;
}

void Engine::OnLoop()
{
	switch (appState)
	{
	case Running:
	{
		OnEvent(&appEvent);
		OnUpdate();
		OnRender();
		break;
	}
	}
}

void Engine::OnEvent(SDL_Event* Event)
{
	while (SDL_PollEvent(Event))
	{
		EventHandler::OnEvent(Event);
	}
}

void Engine::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_ESCAPE)
	{
		OnExit();
	}
}

void Engine::OnUpdate()
{

}

void Engine::OnRender()
{
	glClear (GL_COLOR_BUFFER_BIT);

	SDL_GL_SwapBuffers();
}

void Engine::OnExit()
{
	SwitchState(Exiting);
}

bool Engine::IsExiting()
{
	if (appState == Exiting)
	{
		return true;
	}
	return false;
}

void Engine::SwitchState(AppState state)
{
	Debug::Log("GameState Changed: %s", ToString(state));
	appState = state;
}

const char* Engine::ToString(AppState state)
{
	switch (state)
	{
	case Uninitialized:
		return "Uninitialized";
		break;
	case Running:
		return "Running";
		break;
	case Exiting:
		return "Exiting";
		break;
	default:
		return "State Not Valid";
		break;
	}
}
