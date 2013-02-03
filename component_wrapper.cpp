/*
 ** Lua binding: Component
 ** Generated automatically by tolua++-1.0.92 on 02/03/13 14:05:28.
 */

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int tolua_Component_open(lua_State* tolua_S);

#include "component.h"

/* function to register type */
static void tolua_reg_types(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "Component");
}

/* method: GetType of class  Component */
#ifndef TOLUA_DISABLE_tolua_Component_Component_GetType00
static int tolua_Component_Component_GetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "Component", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		Component* self = (Component*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'GetType'", NULL);
#endif
		{
			unsigned int tolua_ret = (unsigned int) self->GetType();
			tolua_pushnumber(tolua_S, (lua_Number) tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'GetType'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* method: IsEnabled of class  Component */
#ifndef TOLUA_DISABLE_tolua_Component_Component_IsEnabled00
static int tolua_Component_Component_IsEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (!tolua_isusertype(tolua_S, 1, "Component", 0, &tolua_err) || !tolua_isnoobj(tolua_S, 2, &tolua_err))
		goto tolua_lerror;
	else
#endif
	{
		Component* self = (Component*) tolua_tousertype(tolua_S, 1, 0);
#ifndef TOLUA_RELEASE
		if (!self)
			tolua_error(tolua_S, "invalid 'self' in function 'IsEnabled'", NULL);
#endif
		{
			bool tolua_ret = (bool) self->IsEnabled();
			tolua_pushboolean(tolua_S, (bool) tolua_ret);
		}
	}
	return 1;
#ifndef TOLUA_RELEASE
	tolua_lerror: tolua_error(tolua_S, "#ferror in function 'IsEnabled'.", &tolua_err);
	return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE
/* Open function */
TOLUA_API int tolua_Component_open(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	tolua_reg_types(tolua_S);
	tolua_module(tolua_S, NULL, 0);
	tolua_beginmodule(tolua_S, NULL);
	tolua_cclass(tolua_S, "Component", "Component", "", NULL);
	tolua_beginmodule(tolua_S, "Component");
	tolua_function(tolua_S, "GetType", tolua_Component_Component_GetType00);
	tolua_function(tolua_S, "IsEnabled", tolua_Component_Component_IsEnabled00);
	tolua_endmodule(tolua_S);
	tolua_endmodule(tolua_S);
	return 1;
}

#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
TOLUA_API int luaopen_Component (lua_State* tolua_S)
{
	return tolua_Component_open(tolua_S);
};
#endif

