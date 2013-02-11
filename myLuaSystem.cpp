#include <tolua++.h>
#include <string>

#include "myLuaSystem.h"
#include "myEngineWrapper.h"
#include "myLevelSystemWrapper.h"
#include "myEntityWrapper.h"
#include "myGraphicsWrapper.h"
#include "myMathWrapper.h"
#include "myBox2DWrapper.h"

myLuaSystem::myLuaSystem(void) {
	L = lua_open();
	luaL_openlibs(L);
	cL = lua_newthread(L);
}

myLuaSystem::~myLuaSystem(void) {
	lua_close(L);
}

void myLuaSystem::Update() {
	lua_resume(L, 0);
}

void myLuaSystem::Register() {
    tolua_myEngine_open(L);
    tolua_myEntity_open(L);
    tolua_myGraphics_open(L);
    tolua_myLevelSystem_open(L);
    tolua_myMath_open(L);
    tolua_LuaBox2D_open(L);

	lua_register(L, "Sleep", Sleep);
	luaL_loadfile(L, std::string(_currentLevelPath + "/scripts/main.lua").c_str());
}

void myLuaSystem::RunScript(std::string filename) {
	luaL_dofile(cL, filename.c_str());
}

int myLuaSystem::Sleep(lua_State* L) {
	return lua_yield(L, 0);
}
