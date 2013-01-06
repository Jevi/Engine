#ifndef ASSET_H
#define ASSET_H

#include <iostream>
using namespace std;

class Asset
{
public:

	static const int GRAPHICAL = 0;
	static const int AUDIO = 1;

	string filename;        //The filename of the asset
	unsigned int type;            //The type of asset (graphical, audio, video, or font)
	unsigned int scene;            //The scene that the asset is associated with
	bool loaded;                //Is the asset currently loaded?

	//Initializing Ctor
	Asset(string Filename, unsigned int Scene) :
			filename(Filename), scene(Scene), loaded(false)
	{
	}

	//Abstract function, called when the asset is loaded
	virtual void OnLoad() = 0;
	//Abstract function, called when the asset is unloaded
	virtual void OnUnload() = 0;
};

#endif
