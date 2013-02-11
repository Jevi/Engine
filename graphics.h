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
#include "sprite_sheet.h"

class Sprite;
class SpriteSheet;

class Graphics {

public:

	static void DrawPoint(float x, float y);
	static void DrawPoint(float x, float y, float r, float g, float b, float a);
	static void DrawLine(float x1, float y1, float x2, float y2);
	static void DrawLine(float x1, float y1, float x2, float y2, float r, float g, float b, float a);
	static void DrawQuad(float x, float y, float width, float height);
	static void DrawQuad(float x, float y, float width, float height, float r, float g, float b, float a);
	static void DrawQuad(float x, float y, float width, float height, float rotation, float r, float g, float b, float a);
	static void FillQuad(float x, float y, float width, float height);
	static void FillQuad(float x, float y, float width, float height, float r, float g, float b, float a);

	static void DrawTexture(std::shared_ptr<Sprite> sprite, float x, float y, float rotation, float scaleX, float scaleY);
	static void DrawTexture(std::shared_ptr<SpriteSheet> spriteSheet, int row, int column, float x, float y, float rotation, float scaleX, float scaleY);
	static void DrawTexture(std::shared_ptr<Sprite> sprite, b2Vec2* bodyVerticies, b2Vec2 bodyCenter, float rotation);

private:

};

#endif

