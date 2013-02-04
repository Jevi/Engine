#include <tolua++.h>

#include "lua_system.h"
#include "level_system.h"

#include "engine_wrapper.h"
#include "level_system_wrapper.h"
#include "entity_wrapper.h"
#include "component_wrapper.h"

LuaSystem* LuaSystem::instance;

LuaSystem* LuaSystem::GetInstance()
{
	if (!instance)
	{
		instance = new LuaSystem;
	}
	return instance;
}

void LuaSystem::Destroy()
{
	lua_close(L);
}

void LuaSystem::Update()
{
	lua_resume(L, 0);
}

void LuaSystem::Register()
{
	tolua_Engine_open(L);
	tolua_LevelSystem_open(L);
	tolua_Component_open(L);
	tolua_Entity_open(L);

	lua_register(L, "Sleep", Sleep);
	luaL_loadfile(L, string(LevelSystem::GetInstance()->GetCurrentLevelPath() + "/scripts/main.lua").c_str());
}

void LuaSystem::RunScript(string filename)
{
	luaL_dofile(cL, filename.c_str());
}

int LuaSystem::Sleep(lua_State* L)
{
	return lua_yield(L, 0);
}

