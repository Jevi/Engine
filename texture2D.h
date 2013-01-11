#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "asset.h"
#include "graphics.h"

class Texture2D: public Asset
{
public:

	int width, height;
	string filename;

	Texture2D(string Filename, unsigned int Scene) :
			Asset(Filename, Scene), filename(Filename), width(0), height(0), loaded(false)
	{
	}

	~Texture2D(void)
	{
		Unload();
	}

	void Bind();

	void Load();

	void Unload();

protected:

	GLuint textureId;
	bool loaded;

};

#endif

