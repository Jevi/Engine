#include "engine.h"

#include "lua_system.h"
#include "asset_system.h"
#include "level_system.h"

#include "debug.h"

Engine* Engine::instance;

std::string System::_workspace;
std::string System::_currentLevelPath;

Engine::Engine() :
		appState(Uninitialized), appWidth(640), appHeight(480) {
	_workspace = "workspace/demo";
}

void Engine::Destroy() {
	if (instance) {
		Debug::Log(Debug::LOG_ENTRY, "Exiting Engine");
		LuaSystem::GetInstance()->Destroy();
		LevelSystem::GetInstance()->Destroy();
		AssetSystem::GetInstance()->Destroy();
		delete world;
		SDL_Quit();
		delete instance;
		instance = 0;
	}
}

void Engine::Start() {
	if (appState != Uninitialized) {
		return;
	}

	if (Init()) {
		Debug::Log(Debug::LOG_ENTRY, "Engine Initialized Successfully");

		appState = Running;
		AssetSystem::GetInstance()->LoadAssets();
		LevelSystem::GetInstance()->LoadNextLevel();
		LuaSystem::GetInstance()->Register();

		while (!IsExiting()) {
			Heartbeat();
		}
	}
	Destroy();
}

bool Engine::Init() {
	char currentDirectory[FILENAME_MAX];
	getcwd(currentDirectory, sizeof(currentDirectory));
	Debug::Log(Debug::LOG_INFO, "Current Directory: %s", currentDirectory);
	Debug::Log(Debug::LOG_ENTRY, "Initializing Engine");

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		Debug::Log(Debug::LOG_SEVERE, "Could Not Initialize SDL");
		return false;
	}
	Debug::Log(Debug::LOG_INFO, "SDL Initialized");

	SDL_WM_SetCaption("SDL OPENGL ENGINE", NULL);

	if ((appWindow = SDL_SetVideoMode(appWidth, appHeight, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
		Debug::Log(Debug::LOG_SEVERE, "Could Not Set SDL Video Mode");
		return false;
	}
	Debug::Log(Debug::LOG_INFO, "SDL Video Mode Initialized");

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, appWidth, appHeight, 0, 1, -1);
	Debug::Log(Debug::LOG_INFO, "OpenGL Initialized");

	world = new b2World(b2Vec2(0.0f, 9.81f));
	if (!world) {
		Debug::Log(Debug::LOG_SEVERE, "Could Not Initialize Box2D World");
	}
	Debug::Log(Debug::LOG_INFO, "Box2D World Initialized");

	return true;
}

void Engine::Heartbeat() {
	switch (appState) {
		case Running: {
			OnEvent(&appEvent);
			Update();
			Render();
			break;
		}
	}
}

void Engine::OnEvent(SDL_Event* Event) {
	while (SDL_PollEvent(Event)) {
		EventHandler::OnEvent(Event);
	}
}

void Engine::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	if (sym == SDLK_ESCAPE) {
		Exit();
	}
}

void Engine::Update() {
	world->Step(1.0f / 60.0f, 10, 30);
	LuaSystem::GetInstance()->Update();
}

void Engine::Render() {
	glClear (GL_COLOR_BUFFER_BIT);
	LevelSystem::GetInstance()->UpdateLevel();
	SDL_GL_SwapBuffers();
}

void Engine::Exit() {
	SwitchState(Exiting);
}

bool Engine::IsExiting() {
	if (appState == Exiting) {
		return true;
	}
	return false;
}

void Engine::SwitchState(AppState state) {
	Debug::Log(Debug::LOG_INFO, "GameState Changed: %s", ToString(state).c_str());
	appState = state;
}

std::string Engine::ToString(AppState state) {
	switch (state) {
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
