#ifndef MY_LUA_SYSTEM_H
#define MY_LUA_SYSTEM_H

#include <lua.hpp>
#include "mySystem.h"

class myLuaSystem: public mySystem {
public:

    myLuaSystem(void);

    ~myLuaSystem(void);

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
