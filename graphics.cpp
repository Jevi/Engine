#include "graphics.h"
#include "engine_math.h"

void Graphics::DrawLine(float x1, float y1, float x2, float y2)
{
	glPushMatrix();
	glBegin (GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
	glPopMatrix();
}

void Graphics::DrawLine(float x1, float y1, float x2, float y2, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glPushMatrix();
	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);

	DrawLine(x1, y1, x2, y2);

	glDisable(GL_BLEND);
	glColor4f(1, 1, 1, 1);
	glPopMatrix();
}

void Graphics::DrawQuad(float x, float y, float width, float height)
{
	glPushMatrix();
	glBegin (GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
	glPopMatrix();
}

void Graphics::DrawQuad(float x, float y, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	x = EngineMath::MetersToPixels(x);
	y = EngineMath::MetersToPixels(y);

	glPushMatrix();
	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);

	DrawQuad(x, y, width, height);

	glDisable(GL_BLEND);
	glColor4f(1, 1, 1, 1);
	glPopMatrix();
}

void Graphics::DrawQuad(float x, float y, float width, float height, float rotation, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	x = EngineMath::MetersToPixels(x);
	y = EngineMath::MetersToPixels(y);
	rotation = EngineMath::RadiansToDegrees(rotation);

	glPushMatrix();
	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);

	glTranslatef(x, y, 0);
	glRotatef(rotation, 0, 0, 1);
	glTranslatef(-x, -y, 0);

	DrawQuad(x, y, width, height);

	glDisable(GL_BLEND);
	glColor4f(1, 1, 1, 1);
	glPopMatrix();
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

void Graphics::DrawTexture(Sprite* sprite, float x, float y, float rotation, float scale)
{
	x = EngineMath::MetersToPixels(x);
	y = EngineMath::MetersToPixels(y);
	float width = sprite->width * scale;
	float height = sprite->height * scale;
	rotation = EngineMath::RadiansToDegrees(rotation);

	glPushMatrix();
	glEnable (GL_TEXTURE_2D);
	sprite->Bind();

	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTranslatef(x, y, 0);
	glRotatef(rotation, 0, 0, 1);
	glTranslatef(-x, -y, 0);

	glBegin (GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(x, y);
	glTexCoord2f(1, 0);
	glVertex2f(x + width, y);
	glTexCoord2f(1, 1);
	glVertex2f(x + width, y + height);
	glTexCoord2f(0, 1);
	glVertex2f(x, y + height);
	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}