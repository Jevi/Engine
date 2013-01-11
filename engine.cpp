#include "engine.h"

Engine* Engine::instance = 0;
// EntityLoader* el;

Engine::Engine() :
		appState(Uninitialized), appWidth(640), appHeight(480)
{

}

Engine* Engine::GetInstance()
{
	if (instance != 0)
	{
		return instance;
	}

	instance = new Engine;
	return instance;
}

void Engine::Destroy()
{
	// el->Destroy();
	Debug::Log("Exiting Engine");
	SDL_Quit();
	delete this;
}

void Engine::Start()
{
	if (appState != Uninitialized)
	{
		return;
	}

	if (Init())
	{
		appState = Running;
		while (!IsExiting())
		{
			Heartbeat();
		}
	}
	Destroy();
}

bool Engine::Init()
{
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

	/*char currentDirectory[FILENAME_MAX];
	 getcwd(currentDirectory, sizeof(currentDirectory));
	 Debug::Log("Current Directory: %s", currentDirectory);*/

	/*el = EntityLoader::GetInstance();
	 el->LoadAssetsFromXML("res/test.xml");
	 el->SetCurrentScene(0);*/

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, appWidth, appHeight, 0, 1, -1);

	return true;
}

void Engine::Heartbeat()
{
	switch (appState)
	{
	case Running:
	{
		OnEvent(&appEvent);
		Update();
		Render();
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
		Exit();
	}
}

void Engine::Update()
{

}

void Engine::Render()
{
	glClear (GL_COLOR_BUFFER_BIT);

	SDL_GL_SwapBuffers();
}

void Engine::Exit()
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
	Debug::Log("GameState Changed: %s", ToString(state).c_str());
	appState = state;
}

string Engine::ToString(AppState state)
{
	switch (state)
	{
	case Uninitialized:
		return string("Uninitialized");
		break;
	case Running:
		return string("Running");
		break;
	case Exiting:
		return string("Exiting");
		break;
	default:
		return string("State Not Valid");
		break;
	}
}
