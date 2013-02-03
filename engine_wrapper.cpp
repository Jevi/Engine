/*
 ** Lua binding: Engine
 ** Generated automatically by tolua++-1.0.92 on 02/03/13 14:05:32.
 */

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_Engine_open(lua_State* tolua_S);

#include "engine.h"

/* function to register type */
static void tolua_reg_types(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "Engine");
	tolua_usertype(tolua_S, "LevelSystem");
}

/* method: GetInstance of class  Engine */
#ifndef TOLUA_DISABLE_tolua_Engine_Engine_GetInstance00
static int tolua_Engine_Engine_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertable(tolua_S, 1, "Engine", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		{
			Engine* tolua_ret = (Engine*) Engine::GetInstance();
			tolua_pushusertype(tolua_S, (void*) tolua_ret, "Engine");
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetInstance'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: GetAppProject of class  Engine */
#ifndef TOLUA_DISABLE_tolua_Engine_Engine_GetAppProject00
static int tolua_Engine_Engine_GetAppProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "Engine", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		Engine* self = (Engine*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetAppProject'", NULL);
#endif
		{
			string tolua_ret = (string) self->GetAppProject();
			tolua_pushcppstring(tolua_S, (const char*) tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetAppProject'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: GetAppHeight of class  Engine */
#ifndef TOLUA_DISABLE_tolua_Engine_Engine_GetAppHeight00
static int tolua_Engine_Engine_GetAppHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "Engine", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		Engine* self = (Engine*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetAppHeight'", NULL);
#endif
		{
			int tolua_ret = (int) self->GetAppHeight();
			tolua_pushnumber(tolua_S, (lua_Number) tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetAppHeight'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: GetAppWidth of class  Engine */
#ifndef TOLUA_DISABLE_tolua_Engine_Engine_GetAppWidth00
static int tolua_Engine_Engine_GetAppWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "Engine", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		Engine* self = (Engine*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetAppWidth'", NULL);
#endif
		{
			int tolua_ret = (int) self->GetAppWidth();
			tolua_pushnumber(tolua_S, (lua_Number) tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetAppWidth'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: GetAppState of class  Engine */
#ifndef TOLUA_DISABLE_tolua_Engine_Engine_GetAppState00
static int tolua_Engine_Engine_GetAppState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "Engine", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		Engine* self = (Engine*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetAppState'", NULL);
#endif
		{
			string tolua_ret = (string) self->GetAppState();
			tolua_pushcppstring(tolua_S, (const char*) tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetAppState'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: GetLevelSystem of class  Engine */
#ifndef TOLUA_DISABLE_tolua_Engine_Engine_GetLevelSystem00
static int tolua_Engine_Engine_GetLevelSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "Engine", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		Engine* self = (Engine*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetLevelSystem'", NULL);
#endif
		{
			LevelSystem* tolua_ret = (LevelSystem*) self->GetLevelSystem();
			tolua_pushusertype(tolua_S, (void*) tolua_ret, "LevelSystem");
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetLevelSystem'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* Open function */
TOLUA_API int tolua_Engine_open(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	tolua_reg_types(tolua_S);
	tolua_module(tolua_S, NULL, 0);
	tolua_beginmodule(tolua_S, NULL);
	tolua_cclass(tolua_S, "Engine", "Engine", "", NULL);
	tolua_beginmodule(tolua_S, "Engine");
	tolua_function(tolua_S, "GetInstance", tolua_Engine_Engine_GetInstance00);
	tolua_function(tolua_S, "GetAppProject", tolua_Engine_Engine_GetAppProject00);
	tolua_function(tolua_S, "GetAppHeight", tolua_Engine_Engine_GetAppHeight00);
	tolua_function(tolua_S, "GetAppWidth", tolua_Engine_Engine_GetAppWidth00);
	tolua_function(tolua_S, "GetAppState", tolua_Engine_Engine_GetAppState00);
	tolua_function(tolua_S, "GetLevelSystem", tolua_Engine_Engine_GetLevelSystem00);
	tolua_endmodule(tolua_S);
	tolua_endmodule(tolua_S);
	return 1;
}

#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
TOLUA_API int luaopen_Engine (lua_State* tolua_S)
{
	return tolua_Engine_open(tolua_S);
};
#endif

