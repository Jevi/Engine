#ifndef ASSET_H
#define ASSET_H

#include <iostream>
using namespace std;

class Asset
{
public:

	// constant types of Assets
	static const int GRAPHICAL = 0;
	static const int AUDIO = 1;

	string filename;
	unsigned int type;
	unsigned int scene;
	bool loaded;

	Asset(string Filename, unsigned int Scene) :
			filename(Filename), scene(Scene), loaded(false)
	{
	}

	//Abstract function, called when the asset is loaded
	virtual void Load() = 0;
	//Abstract function, called when the asset is unloaded
	virtual void Unload() = 0;
};

#endif
