#include "myEngine.h"

#include "myDebug.h"

myEngine* myEngine::instance;
std::string mySystem::_workspace;
std::string mySystem::_currentLevelPath;

myEngine::myEngine(std::string Workspace, unsigned int Width, unsigned int Height, float xGravity, float yGravity) :
		appState(Uninitialized), appWidth(Width), appHeight(Height), Dt(0), lastUpdate(0) {
	_workspace = Workspace;
	_world = std::shared_ptr < b2World > (new b2World(b2Vec2(xGravity, yGravity)));
    levelSystem = std::unique_ptr < myLevelSystem > (new myLevelSystem());
    luaSystem = std::unique_ptr < myLuaSystem > (new myLuaSystem());
}

myEngine::~myEngine(void) {
    myDebug::Log(myDebug::LOG_ENTRY, "Exiting Engine");
	SDL_Quit();
}

void myEngine::Start() {
	if (appState != Uninitialized) {
		return;
	}

	if (Init()) {
        myDebug::Log(myDebug::LOG_ENTRY, "Engine Initialized Successfully");

		appState = Running;
		assetSystem->LoadAssets();
		levelSystem->LoadNextLevel();
		luaSystem->Register();

		while (!IsExiting()) {
			Heartbeat();
		}
	}
    this->~myEngine();
}

bool myEngine::Init() {
	char currentDirectory[FILENAME_MAX];
	getcwd(currentDirectory, sizeof(currentDirectory));
    myDebug::Log(myDebug::LOG_INFO, "Current Directory: %s", currentDirectory);
    myDebug::Log(myDebug::LOG_ENTRY, "Initializing Engine");

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        myDebug::Log(myDebug::LOG_SEVERE, "Could Not Initialize SDL");
		return false;
	}
    myDebug::Log(myDebug::LOG_INFO, "SDL Initialized");

	SDL_WM_SetCaption("SDL OPENGL ENGINE", NULL);

	if ((appWindow = SDL_SetVideoMode(appWidth, appHeight, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL) {
        myDebug::Log(myDebug::LOG_SEVERE, "Could Not Set SDL Video Mode");
		return false;
	}
    myDebug::Log(myDebug::LOG_INFO, "SDL Video Mode Initialized");

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, appWidth, appHeight, 0, 1, -1);
    myDebug::Log(myDebug::LOG_INFO, "OpenGL Initialized");

	return true;
}

void myEngine::Heartbeat() {
	switch (appState) {
		case Running: {
			OnEvent(&appEvent);
			Update();
			Render();
			break;
		}
	}
}

void myEngine::OnEvent(SDL_Event* Event) {
	while (SDL_PollEvent(Event)) {
        myEventHandler::OnEvent(Event);
	}
}

void myEngine::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	if (sym == SDLK_ESCAPE) {
		Exit();
	}
}

void myEngine::Update() {
	Dt = SDL_GetTicks() - lastUpdate;
	lastUpdate = SDL_GetTicks();
	_world->Step(1.0f / 60.0f, 10, 30);
}

void myEngine::Render() {
	glClear (GL_COLOR_BUFFER_BIT);
	luaSystem->Update();
	levelSystem->UpdateLevel(Dt);
	SDL_GL_SwapBuffers();
}

void myEngine::Exit() {
	SwitchState(Exiting);
}

bool myEngine::IsExiting() {
	if (appState == Exiting) {
		return true;
	}
	return false;
}

void myEngine::SwitchState(AppState state) {
    myDebug::Log(myDebug::LOG_INFO, "GameState Changed: %s", ToString(state).c_str());
	appState = state;
}

std::string myEngine::ToString(AppState state) {
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
