/*
** Lua binding: myMath
** Generated automatically by tolua++-1.0.93 on Mon Feb 11 16:22:11 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_myMath_open (lua_State* tolua_S);

#include "myMath.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"myMath");
}

/* method: DegreesToRadians of class  myMath */
#ifndef TOLUA_DISABLE_tolua_myMath_myMath_DegreesToRadians00
static int tolua_myMath_myMath_DegreesToRadians00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float degrees = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  myMath::DegreesToRadians(degrees);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DegreesToRadians'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RadiansToDegrees of class  myMath */
#ifndef TOLUA_DISABLE_tolua_myMath_myMath_RadiansToDegrees00
static int tolua_myMath_myMath_RadiansToDegrees00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float radians = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  myMath::RadiansToDegrees(radians);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RadiansToDegrees'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PixelsToMeters of class  myMath */
#ifndef TOLUA_DISABLE_tolua_myMath_myMath_PixelsToMeters00
static int tolua_myMath_myMath_PixelsToMeters00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float pixels = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  myMath::PixelsToMeters(pixels);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PixelsToMeters'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MetersToPixels of class  myMath */
#ifndef TOLUA_DISABLE_tolua_myMath_myMath_MetersToPixels00
static int tolua_myMath_myMath_MetersToPixels00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myMath",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float meters = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  myMath::MetersToPixels(meters);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MetersToPixels'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_myMath_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"myMath","myMath","",NULL);
  tolua_beginmodule(tolua_S,"myMath");
   tolua_function(tolua_S,"DegreesToRadians",tolua_myMath_myMath_DegreesToRadians00);
   tolua_function(tolua_S,"RadiansToDegrees",tolua_myMath_myMath_RadiansToDegrees00);
   tolua_function(tolua_S,"PixelsToMeters",tolua_myMath_myMath_PixelsToMeters00);
   tolua_function(tolua_S,"MetersToPixels",tolua_myMath_myMath_MetersToPixels00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_myMath (lua_State* tolua_S) {
 return tolua_myMath_open(tolua_S);
};
#endif

