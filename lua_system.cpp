#include <tolua++.h>

#include "lua_system.h"

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

void LuaSystem::Register()
{
	tolua_Engine_open(L);
	tolua_LevelSystem_open(L);
	tolua_Component_open(L);
	tolua_Entity_open(L);
}

void LuaSystem::RunScript(string filename)
{
	luaL_dofile(L, filename.c_str());
}

