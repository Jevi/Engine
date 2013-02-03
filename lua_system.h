#ifndef LUA_SYSTEM_H
#define LUA_SYSTEM_H

#include <lua.hpp>
#include <string>

using namespace std;

class LuaSystem
{
public:

	static LuaSystem* GetInstance();

	lua_State* GetLuaState()
	{
		return L;
	}

	void Register();

	void Destroy();
	void RunScript(string filename);

private:

	LuaSystem(void)
	{
		L = lua_open();
		luaL_openlibs(L);
	}

	static LuaSystem* instance;
	lua_State* L;

};

#endif // !LUA_SYSTEM_H
