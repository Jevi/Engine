#include "graphics.h"
#include "engine_math.h"

void Graphics::DrawPoint(float x, float y)
{
	glBegin (GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void Graphics::DrawPoint(float x, float y, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);

	DrawPoint(x, y);

	glColor4f(1, 1, 1, 1);
}

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
	x = EngineMath::MetersToPixels(x);
	y = EngineMath::MetersToPixels(y);

	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(r, g, b, a);

	DrawQuad(x, y, width, height);

	glDisable(GL_BLEND);
	glColor4f(1, 1, 1, 1);
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

void Graphics::DrawTexture(Sprite* sprite, float x, float y, float rotation, float scaleX, float scaleY)
{
	x = EngineMath::MetersToPixels(x);
	y = EngineMath::MetersToPixels(y);

	float width = sprite->width * scaleX;
	float height = sprite->height * scaleY;
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
	glVertex2f(x - width / 2, y - height / 2);
	glTexCoord2f(1, 0);
	glVertex2f(x + width / 2, y - height / 2);
	glTexCoord2f(1, 1);
	glVertex2f(x + width / 2, y + height / 2);
	glTexCoord2f(0, 1);
	glVertex2f(x - width / 2, y + height / 2);
	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Graphics::DrawTexture(Sprite* sprite, b2Vec2* bodyVerticies, b2Vec2 bodyCenter, float rotation)
{
	rotation = EngineMath::RadiansToDegrees(rotation);

	glPushMatrix();
	glEnable (GL_TEXTURE_2D);
	sprite->Bind();

	glEnable (GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTranslatef(EngineMath::MetersToPixels(bodyCenter.x), EngineMath::MetersToPixels(bodyCenter.y), 0);
	glRotatef(rotation, 0, 0, 1);

	glBegin (GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(EngineMath::MetersToPixels(bodyVerticies[0].x), EngineMath::MetersToPixels(bodyVerticies[0].y));
	glTexCoord2f(1, 0);
	glVertex2f(EngineMath::MetersToPixels(bodyVerticies[1].x), EngineMath::MetersToPixels(bodyVerticies[1].y));
	glTexCoord2f(1, 1);
	glVertex2f(EngineMath::MetersToPixels(bodyVerticies[2].x), EngineMath::MetersToPixels(bodyVerticies[2].y));
	glTexCoord2f(0, 1);
	glVertex2f(EngineMath::MetersToPixels(bodyVerticies[3].x), EngineMath::MetersToPixels(bodyVerticies[3].y));
	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}