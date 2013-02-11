#ifndef MY_SPRITE_H
#define MY_SPRITE_H

#include "myAsset.h"
#include "myGraphics.h"

class mySprite: public myAsset {
public:

	/*
	 Dimension of texture
	 */
	int width, height;

    mySprite(std::string Id, std::string Filename) :
			myAsset(Id, Filename, myAsset::SPRITE), width(0), height(0), loaded(false) {
	}

    ~mySprite(void) {
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

