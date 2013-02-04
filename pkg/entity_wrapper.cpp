/*
** Lua binding: Entity
** Generated automatically by tolua++-1.0.92 on 02/03/13 22:33:46.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Entity_open (lua_State* tolua_S);

#include "entity.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"Component");
}

/* method: GetId of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_GetId00
static int tolua_Entity_Entity_GetId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetId'", NULL);
#endif
  {
   string tolua_ret = (string)  self->GetId();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponent of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_GetComponent00
static int tolua_Entity_Entity_GetComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  string Name = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponent'", NULL);
#endif
  {
   Component* tolua_ret = (Component*)  self->GetComponent(Name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Component");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponentAt of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_GetComponentAt00
static int tolua_Entity_Entity_GetComponentAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  unsigned int Index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponentAt'", NULL);
#endif
  {
   Component* tolua_ret = (Component*)  self->GetComponentAt(Index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Component");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponentAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddComponent of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_AddComponent00
static int tolua_Entity_Entity_AddComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  Component* NewComponent = ((Component*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddComponent'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddComponent(NewComponent);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponent of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_RemoveComponent00
static int tolua_Entity_Entity_RemoveComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  string Name = ((string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponent'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RemoveComponent(Name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponentAt of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_RemoveComponentAt00
static int tolua_Entity_Entity_RemoveComponentAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  unsigned int Index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponentAt'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RemoveComponentAt(Index);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveComponentAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ToString of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_ToString00
static int tolua_Entity_Entity_ToString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ToString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->ToString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ToString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_GetX00
static int tolua_Entity_Entity_GetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_GetY00
static int tolua_Entity_Entity_GetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAngle of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_GetAngle00
static int tolua_Entity_Entity_GetAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAngle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetAngle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScaleX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_GetScaleX00
static int tolua_Entity_Entity_GetScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScaleX'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetScaleX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScaleY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_GetScaleY00
static int tolua_Entity_Entity_GetScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScaleY'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetScaleY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_SetX00
static int tolua_Entity_Entity_SetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetX'", NULL);
#endif
  {
   self->SetX(x);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_SetY00
static int tolua_Entity_Entity_SetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float y = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetY'", NULL);
#endif
  {
   self->SetY(y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScaleX of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_SetScaleX00
static int tolua_Entity_Entity_SetScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float scalex = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScaleX'", NULL);
#endif
  {
   self->SetScaleX(scalex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScaleY of class  Entity */
#ifndef TOLUA_DISABLE_tolua_Entity_Entity_SetScaleY00
static int tolua_Entity_Entity_SetScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Entity",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Entity* self = (Entity*)  tolua_tousertype(tolua_S,1,0);
  float scaley = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScaleY'", NULL);
#endif
  {
   self->SetScaleY(scaley);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Entity_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Entity","Entity","",NULL);
  tolua_beginmodule(tolua_S,"Entity");
   tolua_function(tolua_S,"GetId",tolua_Entity_Entity_GetId00);
   tolua_function(tolua_S,"GetComponent",tolua_Entity_Entity_GetComponent00);
   tolua_function(tolua_S,"GetComponentAt",tolua_Entity_Entity_GetComponentAt00);
   tolua_function(tolua_S,"AddComponent",tolua_Entity_Entity_AddComponent00);
   tolua_function(tolua_S,"RemoveComponent",tolua_Entity_Entity_RemoveComponent00);
   tolua_function(tolua_S,"RemoveComponentAt",tolua_Entity_Entity_RemoveComponentAt00);
   tolua_function(tolua_S,"ToString",tolua_Entity_Entity_ToString00);
   tolua_function(tolua_S,"GetX",tolua_Entity_Entity_GetX00);
   tolua_function(tolua_S,"GetY",tolua_Entity_Entity_GetY00);
   tolua_function(tolua_S,"GetAngle",tolua_Entity_Entity_GetAngle00);
   tolua_function(tolua_S,"GetScaleX",tolua_Entity_Entity_GetScaleX00);
   tolua_function(tolua_S,"GetScaleY",tolua_Entity_Entity_GetScaleY00);
   tolua_function(tolua_S,"SetX",tolua_Entity_Entity_SetX00);
   tolua_function(tolua_S,"SetY",tolua_Entity_Entity_SetY00);
   tolua_function(tolua_S,"SetScaleX",tolua_Entity_Entity_SetScaleX00);
   tolua_function(tolua_S,"SetScaleY",tolua_Entity_Entity_SetScaleY00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Entity (lua_State* tolua_S) {
 return tolua_Entity_open(tolua_S);
};
#endif

