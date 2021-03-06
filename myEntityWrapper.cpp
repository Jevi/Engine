/*
** Lua binding: myEntity
** Generated automatically by tolua++-1.0.93 on Wed Feb 13 14:35:37 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_myEntity_open (lua_State* tolua_S);

#include "myEntity.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_myEntity__Scale (lua_State* tolua_S)
{
 myEntity::Scale* self = (myEntity::Scale*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"b2BodyDef");
 tolua_usertype(tolua_S,"myEntity");
 tolua_usertype(tolua_S,"myEntity::Scale");
}

/* get function: x of class  Scale */
#ifndef TOLUA_DISABLE_tolua_get_myEntity__Scale_x
static int tolua_get_myEntity__Scale_x(lua_State* tolua_S)
{
  myEntity::Scale* self = (myEntity::Scale*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Scale */
#ifndef TOLUA_DISABLE_tolua_set_myEntity__Scale_x
static int tolua_set_myEntity__Scale_x(lua_State* tolua_S)
{
  myEntity::Scale* self = (myEntity::Scale*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  Scale */
#ifndef TOLUA_DISABLE_tolua_get_myEntity__Scale_y
static int tolua_get_myEntity__Scale_y(lua_State* tolua_S)
{
  myEntity::Scale* self = (myEntity::Scale*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Scale */
#ifndef TOLUA_DISABLE_tolua_set_myEntity__Scale_y
static int tolua_set_myEntity__Scale_y(lua_State* tolua_S)
{
  myEntity::Scale* self = (myEntity::Scale*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Scale */
#ifndef TOLUA_DISABLE_tolua_myEntity_myEntity_Scale_new00
static int tolua_myEntity_myEntity_Scale_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myEntity::Scale",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float X = ((float)  tolua_tonumber(tolua_S,2,0));
  float Y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   myEntity::Scale* tolua_ret = (myEntity::Scale*)  Mtolua_new((myEntity::Scale)(X,Y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myEntity::Scale");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Scale */
#ifndef TOLUA_DISABLE_tolua_myEntity_myEntity_Scale_new00_local
static int tolua_myEntity_myEntity_Scale_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myEntity::Scale",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float X = ((float)  tolua_tonumber(tolua_S,2,0));
  float Y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   myEntity::Scale* tolua_ret = (myEntity::Scale*)  Mtolua_new((myEntity::Scale)(X,Y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myEntity::Scale");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: bodyDef of class  myEntity */
#ifndef TOLUA_DISABLE_tolua_get_myEntity_bodyDef
static int tolua_get_myEntity_bodyDef(lua_State* tolua_S)
{
  myEntity* self = (myEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bodyDef'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->bodyDef,"b2BodyDef");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: bodyDef of class  myEntity */
#ifndef TOLUA_DISABLE_tolua_set_myEntity_bodyDef
static int tolua_set_myEntity_bodyDef(lua_State* tolua_S)
{
  myEntity* self = (myEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'bodyDef'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"b2BodyDef",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->bodyDef = *((b2BodyDef*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scale of class  myEntity */
#ifndef TOLUA_DISABLE_tolua_get_myEntity_scale
static int tolua_get_myEntity_scale(lua_State* tolua_S)
{
  myEntity* self = (myEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->scale,"myEntity::Scale");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scale of class  myEntity */
#ifndef TOLUA_DISABLE_tolua_set_myEntity_scale
static int tolua_set_myEntity_scale(lua_State* tolua_S)
{
  myEntity* self = (myEntity*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"myEntity::Scale",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scale = *((myEntity::Scale*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_myEntity_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"myEntity","myEntity","",NULL);
  tolua_beginmodule(tolua_S,"myEntity");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Scale","myEntity::Scale","",tolua_collect_myEntity__Scale);
   #else
   tolua_cclass(tolua_S,"Scale","myEntity::Scale","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Scale");
    tolua_variable(tolua_S,"x",tolua_get_myEntity__Scale_x,tolua_set_myEntity__Scale_x);
    tolua_variable(tolua_S,"y",tolua_get_myEntity__Scale_y,tolua_set_myEntity__Scale_y);
    tolua_function(tolua_S,"new",tolua_myEntity_myEntity_Scale_new00);
    tolua_function(tolua_S,"new_local",tolua_myEntity_myEntity_Scale_new00_local);
    tolua_function(tolua_S,".call",tolua_myEntity_myEntity_Scale_new00_local);
   tolua_endmodule(tolua_S);
   tolua_variable(tolua_S,"bodyDef",tolua_get_myEntity_bodyDef,tolua_set_myEntity_bodyDef);
   tolua_variable(tolua_S,"scale",tolua_get_myEntity_scale,tolua_set_myEntity_scale);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_myEntity (lua_State* tolua_S) {
 return tolua_myEntity_open(tolua_S);
};
#endif

