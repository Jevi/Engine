/*
** Lua binding: myEngine
** Generated automatically by tolua++-1.0.93 on Mon Feb 11 16:22:11 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_myEngine_open (lua_State* tolua_S);

#include "myEngine.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"myLevelSystem");
 tolua_usertype(tolua_S,"myEngine");
}

/* method: GetInstance of class  myEngine */
#ifndef TOLUA_DISABLE_tolua_myEngine_myEngine_GetInstance00
static int tolua_myEngine_myEngine_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myEngine* tolua_ret = (myEngine*)  myEngine::GetInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myEngine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppProject of class  myEngine */
#ifndef TOLUA_DISABLE_tolua_myEngine_myEngine_GetAppProject00
static int tolua_myEngine_myEngine_GetAppProject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myEngine* self = (myEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppProject'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetAppProject();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppProject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppHeight of class  myEngine */
#ifndef TOLUA_DISABLE_tolua_myEngine_myEngine_GetAppHeight00
static int tolua_myEngine_myEngine_GetAppHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myEngine* self = (myEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppHeight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetAppHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppWidth of class  myEngine */
#ifndef TOLUA_DISABLE_tolua_myEngine_myEngine_GetAppWidth00
static int tolua_myEngine_myEngine_GetAppWidth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myEngine* self = (myEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppWidth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetAppWidth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppWidth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAppState of class  myEngine */
#ifndef TOLUA_DISABLE_tolua_myEngine_myEngine_GetAppState00
static int tolua_myEngine_myEngine_GetAppState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myEngine* self = (myEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAppState'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetAppState();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAppState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLevelSystem of class  myEngine */
#ifndef TOLUA_DISABLE_tolua_myEngine_myEngine_GetLevelSystem00
static int tolua_myEngine_myEngine_GetLevelSystem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myEngine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myEngine* self = (myEngine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLevelSystem'", NULL);
#endif
  {
   myLevelSystem* tolua_ret = (myLevelSystem*)  self->GetLevelSystem();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myLevelSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLevelSystem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_myEngine_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"myEngine","myEngine","",NULL);
  tolua_beginmodule(tolua_S,"myEngine");
   tolua_function(tolua_S,"GetInstance",tolua_myEngine_myEngine_GetInstance00);
   tolua_function(tolua_S,"GetAppProject",tolua_myEngine_myEngine_GetAppProject00);
   tolua_function(tolua_S,"GetAppHeight",tolua_myEngine_myEngine_GetAppHeight00);
   tolua_function(tolua_S,"GetAppWidth",tolua_myEngine_myEngine_GetAppWidth00);
   tolua_function(tolua_S,"GetAppState",tolua_myEngine_myEngine_GetAppState00);
   tolua_function(tolua_S,"GetLevelSystem",tolua_myEngine_myEngine_GetLevelSystem00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_myEngine (lua_State* tolua_S) {
 return tolua_myEngine_open(tolua_S);
};
#endif

