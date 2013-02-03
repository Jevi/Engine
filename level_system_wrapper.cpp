/*
 ** Lua binding: LevelSystem
 ** Generated automatically by tolua++-1.0.92 on 02/03/13 14:05:22.
 */

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_LevelSystem_open(lua_State* tolua_S);

#include "level_system.h"

/* function to register type */
static void tolua_reg_types(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "LevelSystem");
	tolua_usertype(tolua_S, "Entity");
}

/* method: GetCurrentLevel of class  LevelSystem */
#ifndef TOLUA_DISABLE_tolua_LevelSystem_LevelSystem_GetCurrentLevel00
static int tolua_LevelSystem_LevelSystem_GetCurrentLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "LevelSystem", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		LevelSystem* self = (LevelSystem*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetCurrentLevel'", NULL);
#endif
		{
			unsigned int tolua_ret = (unsigned int) self->GetCurrentLevel();
			tolua_pushnumber(tolua_S, (lua_Number) tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetCurrentLevel'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: GetTotalEntities of class  LevelSystem */
#ifndef TOLUA_DISABLE_tolua_LevelSystem_LevelSystem_GetTotalEntities00
static int tolua_LevelSystem_LevelSystem_GetTotalEntities00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "LevelSystem", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		LevelSystem* self = (LevelSystem*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetTotalEntities'", NULL);
#endif
		{
			unsigned int tolua_ret = (unsigned int) self->GetTotalEntities();
			tolua_pushnumber(tolua_S, (lua_Number) tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetTotalEntities'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: GetEntity of class  LevelSystem */
#ifndef TOLUA_DISABLE_tolua_LevelSystem_LevelSystem_GetEntity00
static int tolua_LevelSystem_LevelSystem_GetEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "LevelSystem", 0, &tolua_err) || !tolua_iscppstring(tolua_S, 2, 0, &tolua_err) || !tolua_isnoobj(tolua_S, 3, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		LevelSystem* self = (LevelSystem*) tolua_tousertype(tolua_S, 1, 0);
		string Id = ((string) tolua_tocppstring(tolua_S, 2, 0));
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetEntity'", NULL);
#endif
		{
			Entity* tolua_ret = (Entity*) self->GetEntity(Id);
			tolua_pushusertype(tolua_S, (void*) tolua_ret, "Entity");
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetEntity'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: GetEntity of class  LevelSystem */
#ifndef TOLUA_DISABLE_tolua_LevelSystem_LevelSystem_GetEntity01
static int tolua_LevelSystem_LevelSystem_GetEntity01(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "LevelSystem", 0, &tolua_err) || !tolua_isnumber(tolua_S, 2, 0, &tolua_err) || !tolua_isnoobj(tolua_S, 3, &tolua_err))
		goto tolua_lerror;
	else
	{
		LevelSystem* self = (LevelSystem*) tolua_tousertype(tolua_S, 1, 0);
		unsigned int Idx = ((unsigned int) tolua_tonumber(tolua_S, 2, 0));
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetEntity'", NULL);
#endif
		{
			Entity* tolua_ret = (Entity*) self->GetEntity(Idx);
			tolua_pushusertype(tolua_S, (void*) tolua_ret, "Entity");
		}
	}
	return 1;
	tolua_lerror: return tolua_LevelSystem_LevelSystem_GetEntity00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE
/* Open function */
TOLUA_API int tolua_LevelSystem_open(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	tolua_reg_types(tolua_S);
	tolua_module(tolua_S, NULL, 0);
	tolua_beginmodule(tolua_S, NULL);
	tolua_cclass(tolua_S, "LevelSystem", "LevelSystem", "", NULL);
	tolua_beginmodule(tolua_S, "LevelSystem");
	tolua_function(tolua_S, "GetCurrentLevel", tolua_LevelSystem_LevelSystem_GetCurrentLevel00);
	tolua_function(tolua_S, "GetTotalEntities", tolua_LevelSystem_LevelSystem_GetTotalEntities00);
	tolua_function(tolua_S, "GetEntity", tolua_LevelSystem_LevelSystem_GetEntity00);
	tolua_function(tolua_S, "GetEntity", tolua_LevelSystem_LevelSystem_GetEntity01);
	tolua_endmodule(tolua_S);
	tolua_endmodule(tolua_S);
	return 1;
}

#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
TOLUA_API int luaopen_LevelSystem (lua_State* tolua_S)
{
	return tolua_LevelSystem_open(tolua_S);
};
#endif

