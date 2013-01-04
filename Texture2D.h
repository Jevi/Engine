#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "Asset.h"
#include "Graphics.h"

class Graphics;

class Texture2D: public Asset
{
public:

	int width, height;

	Texture2D(string Filename, unsigned int Scene) :
			Asset(Filename, Scene), filename(Filename), width(0), height(0)
	{
	}

	~Texture2D(void)
	{
		OnUnLoad();
	}

	void Bind();

	void OnLoad();

	void OnUnLoad();

protected:

	GLuint textureId;
	bool loaded;
	string filename;
	
};

#endif

