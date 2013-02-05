#ifndef SPRITE_H
#define SPRITE_H

#include <sstream>
#include <string>
#include "tinyxml2.h"

#include "asset.h"
#include "graphics.h"
#include "engine_math.h"

using namespace tinyxml2;
using namespace std;

class Sprite: public Asset {
public:

	/*
	 Dimension of texture
	 */
	int width, height;
	std::string id;
	/*
	 asset location on hdd
	 */
	std::string filename;
	Sprite(std::string Id, std::string Filename) :
			Asset(Id, Filename, Asset::GRAPHICAL), id(Id), filename(Filename), width(0), height(0), loaded(false) {
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

