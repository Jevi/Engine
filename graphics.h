#ifndef GRAPHICS_H
#define GRAPHICS_H

#define NO_SDL_GLEXT
#include <GL/glew.h>

#ifdef _WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#endif

#include <Box2D/Box2D.h>
#include "sprite.h"

class Sprite;

class Graphics
{

public:

	static void DrawPoint(float x, float y);
	static void DrawPoint(float x, float y, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	static void DrawLine(float x1, float y1, float x2, float y2);
	static void DrawLine(float x1, float y1, float x2, float y2, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	static void DrawQuad(float x, float y, float width, float height);
	static void DrawQuad(float x, float y, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	static void DrawQuad(float x, float y, float width, float height, float rotation, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	static void FillQuad(float x, float y, float width, float height);
	static void FillQuad(float x, float y, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a);

	static void DrawTexture(Sprite* sprite, float x, float y, float rotation, float scaleX, float scaleY);
	static void DrawTexture(Sprite* sprite, b2Vec2* bodyVerticies, b2Vec2 bodyCenter, float rotation);

private:

};

#endif

