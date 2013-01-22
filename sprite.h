#ifndef SPRITE_H
#define SPRITE_H

#include <sstream>
#include <string>
#include "tinyxml2.h"

#include "asset.h"
#include "graphics.h"

using namespace tinyxml2;
using namespace std;

class Sprite: public Asset
{
public:

	/*
	 Dimension of texture
	 */
	int width, height;
	string id;
	/*
	 asset location on hdd
	 */
	string filename;
	Sprite(string Id, string Filename) :
			Asset(Id, Filename, Asset::GRAPHICAL), id(Id), filename(Filename), width(0), height(0), loaded(false)
	{
	}

	~Sprite(void)
	{
		Unload();
	}

	void Bind();

	bool Load();

	void Unload();

	string ToString();

protected:

	GLuint textureId;
	bool loaded;

};

#endif

