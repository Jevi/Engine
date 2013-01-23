#include "engine.h"

Engine* Engine::instance;
string Engine::appProject;

Engine::Engine() :
		appState(Uninitialized), appWidth(640), appHeight(480)
{
	appProject = "workspace/demo";
	assetLoader = AssetLoader::GetInstance();
	levelManager = LevelManager::GetInstance();
}

Engine* Engine::GetInstance()
{
	if (!instance)
	{
		instance = new Engine;
	}
	return instance;
}

void Engine::Destroy()
{
    Debug::Log(Debug::LOG_INFO, "Exiting Engine");
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
        Debug::Log(Debug::LOG_INFO, "\n----- Engine Initialized Successfully -----\n");

		if (assetLoader->LoadAssets())
		{
			levelManager->LoadNextLevel();

			appState = Running;
			while (!IsExiting())
			{
				Heartbeat();
			}
		}
	}
	Destroy();
}

bool Engine::Init()
{
	char currentDirectory[FILENAME_MAX];
	getcwd(currentDirectory, sizeof(currentDirectory));
    Debug::Log(Debug::LOG_INFO, "Current Directory: %s\n", currentDirectory);
    Debug::Log(Debug::LOG_ENTRY, "----- Initializing Engine -----\n");

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
        Debug::Log(Debug::LOG_SEVERE, "Could Not Initialize SDL");
		return false;
	}
    Debug::Log(Debug::LOG_DEBUG, "SDL Initialized");

	SDL_WM_SetCaption("SDL OPENGL ENGINE", NULL);

	if ((appWindow = SDL_SetVideoMode(appWidth, appHeight, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
	{
        Debug::Log(Debug::LOG_SEVERE, "Could Not Set SDL Video Mode");
		return false;
	}
    Debug::Log(Debug::LOG_DEBUG, "SDL Video Mode Initialized");

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, appWidth, appHeight, 0, 1, -1);
    Debug::Log(Debug::LOG_DEBUG, "OpenGL Initialized");
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
    Debug::Log(Debug::LOG_DEBUG, "GameState Changed: %s", ToString(state).c_str());
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
