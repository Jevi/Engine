#ifndef SPRITE_H
#define SPRITE_H

#include "asset.h"
#include "graphics.h"

class Sprite: public Asset {
public:

	/*
	 Dimension of texture
	 */
	int width, height;

	Sprite(std::string Id, std::string Filename) :
			Asset(Id, Filename, Asset::SPRITE), width(0), height(0), loaded(false) {
	}

	~Sprite(void) {
		Unload();
	}

	void Bind();

	bool Load();

	void Unload();

	std::string ToString();

protected:

	GLuint textureId;
	bool loaded;

};

#endif

