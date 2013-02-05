#ifndef LUA_SYSTEM_H
#define LUA_SYSTEM_H

#include <iostream>
#include <lua.hpp>

class LuaSystem
{
public:

	static LuaSystem* GetInstance();

	void Destroy();

	void Register();

	void Update();

	void RunScript(std::string filename);

	lua_State* GetLuaState()
	{
		return L;
	}

private:

	LuaSystem();
	~LuaSystem()
	{
	}

	static LuaSystem* instance;
	lua_State* L;
	lua_State* cL;

	static int Sleep(lua_State* L);

};

#endif // !LUA_SYSTEM_H
