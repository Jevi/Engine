#ifndef LUA_SYSTEM_H
#define LUA_SYSTEM_H

#include <lua.hpp>
#include "system.h"

class LuaSystem: public System {
public:

	LuaSystem(void);

	~LuaSystem(void);

	void Register();

	void Update();

	void RunScript(std::string filename);

	lua_State* GetLuaState() {
		return L;
	}

private:

	lua_State* L;
	lua_State* cL;

	static int Sleep(lua_State* L);
};

#endif // !LUA_SYSTEM_H
