/*
** Lua binding: myLevelSystem
** Generated automatically by tolua++-1.0.93 on Wed Feb 13 14:35:37 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_myLevelSystem_open (lua_State* tolua_S);

#include "myLevelSystem.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"myLevelSystem");
 tolua_usertype(tolua_S,"myEntity");
}

/* method: GetEntityAt of class  myLevelSystem */
#ifndef TOLUA_DISABLE_tolua_myLevelSystem_myLevelSystem_GetEntityAt00
static int tolua_myLevelSystem_myLevelSystem_GetEntityAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myLevelSystem",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myLevelSystem* self = (myLevelSystem*)  tolua_tousertype(tolua_S,1,0);
  unsigned int Idx = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEntityAt'", NULL);
#endif
  {
   myEntity* tolua_ret = (myEntity*)  self->GetEntityAt(Idx);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myEntity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEntityAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEntity of class  myLevelSystem */
#ifndef TOLUA_DISABLE_tolua_myLevelSystem_myLevelSystem_GetEntity00
static int tolua_myLevelSystem_myLevelSystem_GetEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myLevelSystem",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myLevelSystem* self = (myLevelSystem*)  tolua_tousertype(tolua_S,1,0);
  std::string Id = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEntity'", NULL);
#endif
  {
   myEntity* tolua_ret = (myEntity*)  self->GetEntity(Id);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myEntity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumEntity of class  myLevelSystem */
#ifndef TOLUA_DISABLE_tolua_myLevelSystem_myLevelSystem_GetNumEntity00
static int tolua_myLevelSystem_myLevelSystem_GetNumEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myLevelSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myLevelSystem* self = (myLevelSystem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumEntity'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetNumEntity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_myLevelSystem_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"myLevelSystem","myLevelSystem","",NULL);
  tolua_beginmodule(tolua_S,"myLevelSystem");
   tolua_function(tolua_S,"GetEntityAt",tolua_myLevelSystem_myLevelSystem_GetEntityAt00);
   tolua_function(tolua_S,"GetEntity",tolua_myLevelSystem_myLevelSystem_GetEntity00);
   tolua_function(tolua_S,"GetNumEntity",tolua_myLevelSystem_myLevelSystem_GetNumEntity00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_myLevelSystem (lua_State* tolua_S) {
 return tolua_myLevelSystem_open(tolua_S);
};
#endif

