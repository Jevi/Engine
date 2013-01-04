#include "Graphics.h"

void Graphics::DrawLine(float x1, float y1, float x2, float y2)
{
	glBegin (GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void Graphics::DrawLine(float x1, float y1, float x2, float y2, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);

	DrawLine(x1, y1, x2, y2);

	glDisable(GL_BLEND);
	glColor4f(1, 1, 1, 1);
}

void Graphics::DrawQuad(float x, float y, float width, float height)
{
	glBegin (GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

void Graphics::DrawQuad(float x, float y, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);

	DrawQuad(x, y, width, height);

	glDisable(GL_BLEND);
	glColor4f(1, 1, 1, 1);
}

void Graphics::FillQuad(float x, float y, float width, float height)
{
	glBegin (GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

void Graphics::FillQuad(float x, float y, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);

	FillQuad(x, y, width, height);

	glDisable(GL_BLEND);
	glColor4f(1, 1, 1, 1);
}

void Graphics::DrawTexture(Texture2D* texture, float x, float y)
{
	glEnable (GL_TEXTURE_2D);
	texture->Bind();

	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin (GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(x, y);
	glTexCoord2f(1, 0);
	glVertex2f(x + texture->width, y);
	glTexCoord2f(1, 1);
	glVertex2f(x + texture->width, y + texture->height);
	glTexCoord2f(0, 1);
	glVertex2f(x, y + texture->height);
	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
}