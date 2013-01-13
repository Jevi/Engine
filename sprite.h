#ifndef SPRITE_H
#define SPRITE_H

#include "asset.h"
#include "graphics.h"

class Sprite: public Asset
{
public:

	/*
	 Dimension of texture
	 */
	int width, height;
	/*
	 asset location on hdd
	 */
	string filename;

	Sprite(string Filename, unsigned int Scene) :
			Asset(Filename, Scene), filename(Filename), width(0), height(0), loaded(false)
	{
	}

	~Sprite(void)
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

