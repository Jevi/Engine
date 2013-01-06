#ifndef GRAPHICS_H
#define GRAPHICS_H

#define NO_SDL_GLEXT
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>

#include "debug.h"
#include "texture2D.h"

class Texture2D;

class Graphics
{

public:

	static void DrawLine(float x1, float y1, float x2, float y2);
	static void DrawLine(float x1, float y1, float x2, float y2, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	static void DrawQuad(float x, float y, float width, float height);
	static void DrawQuad(float x, float y, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	static void FillQuad(float x, float y, float width, float height);
	static void FillQuad(float x, float y, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a);

	static void DrawTexture(Texture2D* texture, float x, float y);

private:

};

#endif
