#include <tolua++.h>
#include <string>

#include "lua_system.h"
#include "engine_wrapper.h"
#include "level_system_wrapper.h"

LuaSystem::LuaSystem(void) {
	L = lua_open();
	luaL_openlibs(L);
	cL = lua_newthread(L);
}

LuaSystem::~LuaSystem(void) {
	lua_close(L);
}

void LuaSystem::Update() {
	lua_resume(L, 0);
}

void LuaSystem::Register() {
	 tolua_Engine_open(L);
	 tolua_LevelSyStem_open(L);
	 // tolua_Component_open(L);
	 // tolua_Entity_open(L);*/

	lua_register(L, "Sleep", Sleep);
	luaL_loadfile(L, std::string(_currentLevelPath + "/scripts/main.lua").c_str());
}

void LuaSystem::RunScript(std::string filename) {
	luaL_dofile(cL, filename.c_str());
}

int LuaSystem::Sleep(lua_State* L) {
	return lua_yield(L, 0);
}