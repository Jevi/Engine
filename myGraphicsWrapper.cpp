/*
** Lua binding: myGraphics
** Generated automatically by tolua++-1.0.93 on Mon Feb 11 16:22:11 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_myGraphics_open (lua_State* tolua_S);

#include "myGraphics.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"myGraphics");
}

/* method: DrawPoint of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_DrawPoint00
static int tolua_myGraphics_myGraphics_DrawPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   myGraphics::DrawPoint(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawPoint of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_DrawPoint01
static int tolua_myGraphics_myGraphics_DrawPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float r = ((float)  tolua_tonumber(tolua_S,4,0));
  float g = ((float)  tolua_tonumber(tolua_S,5,0));
  float b = ((float)  tolua_tonumber(tolua_S,6,0));
  float a = ((float)  tolua_tonumber(tolua_S,7,0));
  {
   myGraphics::DrawPoint(x,y,r,g,b,a);
  }
 }
 return 0;
tolua_lerror:
 return tolua_myGraphics_myGraphics_DrawPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawLine of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_DrawLine00
static int tolua_myGraphics_myGraphics_DrawLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float y1 = ((float)  tolua_tonumber(tolua_S,3,0));
  float x2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float y2 = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   myGraphics::DrawLine(x1,y1,x2,y2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawLine of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_DrawLine01
static int tolua_myGraphics_myGraphics_DrawLine01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x1 = ((float)  tolua_tonumber(tolua_S,2,0));
  float y1 = ((float)  tolua_tonumber(tolua_S,3,0));
  float x2 = ((float)  tolua_tonumber(tolua_S,4,0));
  float y2 = ((float)  tolua_tonumber(tolua_S,5,0));
  float r = ((float)  tolua_tonumber(tolua_S,6,0));
  float g = ((float)  tolua_tonumber(tolua_S,7,0));
  float b = ((float)  tolua_tonumber(tolua_S,8,0));
  float a = ((float)  tolua_tonumber(tolua_S,9,0));
  {
   myGraphics::DrawLine(x1,y1,x2,y2,r,g,b,a);
  }
 }
 return 0;
tolua_lerror:
 return tolua_myGraphics_myGraphics_DrawLine00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawQuad of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_DrawQuad00
static int tolua_myGraphics_myGraphics_DrawQuad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   myGraphics::DrawQuad(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawQuad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawQuad of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_DrawQuad01
static int tolua_myGraphics_myGraphics_DrawQuad01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  float r = ((float)  tolua_tonumber(tolua_S,6,0));
  float g = ((float)  tolua_tonumber(tolua_S,7,0));
  float b = ((float)  tolua_tonumber(tolua_S,8,0));
  float a = ((float)  tolua_tonumber(tolua_S,9,0));
  {
   myGraphics::DrawQuad(x,y,width,height,r,g,b,a);
  }
 }
 return 0;
tolua_lerror:
 return tolua_myGraphics_myGraphics_DrawQuad00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawQuad of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_DrawQuad02
static int tolua_myGraphics_myGraphics_DrawQuad02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  float rotation = ((float)  tolua_tonumber(tolua_S,6,0));
  float r = ((float)  tolua_tonumber(tolua_S,7,0));
  float g = ((float)  tolua_tonumber(tolua_S,8,0));
  float b = ((float)  tolua_tonumber(tolua_S,9,0));
  float a = ((float)  tolua_tonumber(tolua_S,10,0));
  {
   myGraphics::DrawQuad(x,y,width,height,rotation,r,g,b,a);
  }
 }
 return 0;
tolua_lerror:
 return tolua_myGraphics_myGraphics_DrawQuad01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: FillQuad of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_FillQuad00
static int tolua_myGraphics_myGraphics_FillQuad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   myGraphics::FillQuad(x,y,width,height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FillQuad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FillQuad of class  myGraphics */
#ifndef TOLUA_DISABLE_tolua_myGraphics_myGraphics_FillQuad01
static int tolua_myGraphics_myGraphics_FillQuad01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myGraphics",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,10,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float width = ((float)  tolua_tonumber(tolua_S,4,0));
  float height = ((float)  tolua_tonumber(tolua_S,5,0));
  float r = ((float)  tolua_tonumber(tolua_S,6,0));
  float g = ((float)  tolua_tonumber(tolua_S,7,0));
  float b = ((float)  tolua_tonumber(tolua_S,8,0));
  float a = ((float)  tolua_tonumber(tolua_S,9,0));
  {
   myGraphics::FillQuad(x,y,width,height,r,g,b,a);
  }
 }
 return 0;
tolua_lerror:
 return tolua_myGraphics_myGraphics_FillQuad00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_myGraphics_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"myGraphics","myGraphics","",NULL);
  tolua_beginmodule(tolua_S,"myGraphics");
   tolua_function(tolua_S,"DrawPoint",tolua_myGraphics_myGraphics_DrawPoint00);
   tolua_function(tolua_S,"DrawPoint",tolua_myGraphics_myGraphics_DrawPoint01);
   tolua_function(tolua_S,"DrawLine",tolua_myGraphics_myGraphics_DrawLine00);
   tolua_function(tolua_S,"DrawLine",tolua_myGraphics_myGraphics_DrawLine01);
   tolua_function(tolua_S,"DrawQuad",tolua_myGraphics_myGraphics_DrawQuad00);
   tolua_function(tolua_S,"DrawQuad",tolua_myGraphics_myGraphics_DrawQuad01);
   tolua_function(tolua_S,"DrawQuad",tolua_myGraphics_myGraphics_DrawQuad02);
   tolua_function(tolua_S,"FillQuad",tolua_myGraphics_myGraphics_FillQuad00);
   tolua_function(tolua_S,"FillQuad",tolua_myGraphics_myGraphics_FillQuad01);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_myGraphics (lua_State* tolua_S) {
 return tolua_myGraphics_open(tolua_S);
};
#endif

