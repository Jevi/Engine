#include "Texture2D.h"

void Texture2D::Bind()
{
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture2D::OnLoad()
{
	if (loaded)
	{
		OnUnload();
	}

	SDL_Surface* image = IMG_Load(filename.c_str());

	if (image == NULL)
	{
		Debug::Log("Could Not Load: %s", filename.c_str());
		return;
	}
	Debug::Log("Loaded: %s", filename.c_str());

	width = image->w;
	height = image->h;

	if ((width == 0) || (height == 0))
	{
		return;
	}

	GLuint tempId;
	glGenTextures(1, &tempId);
	textureId = tempId;

	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
	SDL_FreeSurface(image);
	loaded = true;
}

void Texture2D::OnUnload()
{
	if (loaded)
	{
		GLuint tempId;
		tempId = textureId;
		glDeleteTextures(1, &tempId);

		width = height = 0;
		filename = "";
		loaded = false;
	}
}