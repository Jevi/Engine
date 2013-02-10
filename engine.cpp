#include "engine.h"

#include "debug.h"

Engine* Engine::instance;
std::string System::_workspace;
std::string System::_currentLevelPath;

Engine::Engine(std::string Workspace, unsigned int Width, unsigned int Height, float xGravity, float yGravity) :
		appState(Uninitialized), appWidth(Width), appHeight(Height), Dt(0), lastUpdate(0) {
	_workspace = Workspace;
	_world = std::shared_ptr < b2World > (new b2World(b2Vec2(xGravity, yGravity)));
	levelSystem = std::unique_ptr < LevelSystem > (new LevelSystem());
	luaSystem = std::unique_ptr < LuaSystem > (new LuaSystem());
}

Engine::~Engine(void) {
	Debug::Log(Debug::LOG_ENTRY, "Exiting Engine");
	SDL_Quit();
}

void Engine::Start() {
	if (appState != Uninitialized) {
		return;
	}

	if (Init()) {
		Debug::Log(Debug::LOG_ENTRY, "Engine Initialized Successfully");

		appState = Running;
		assetSystem->LoadAssets();
		levelSystem->LoadNextLevel();
		luaSystem->Register();

		while (!IsExiting()) {
			Heartbeat();
		}
	}
	this->~Engine();
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
	Dt = SDL_GetTicks() - lastUpdate;
	lastUpdate = SDL_GetTicks();
	_world->Step(1.0f / 60.0f, 10, 30);
	luaSystem->Update();
}

void Engine::Render() {
	glClear (GL_COLOR_BUFFER_BIT);
	levelSystem->UpdateLevel(Dt);
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
