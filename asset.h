#ifndef ASSET_H
#define ASSET_H

#include <iostream>
using namespace std;

class Asset
{
public:

	// constant types of Assets

	static const unsigned int GRAPHICAL = 0;
	static const unsigned int AUDIO = 1;

	static string TypeToString(unsigned int Type)
	{
		switch (Type)
		{
		case GRAPHICAL:
			return string("GRAPHICAL");
			break;
		case AUDIO:
			return string("AUDIO");
			break;
		}
	}

	/*
	 asset location on hdd
	 */
	string filename;
	/*
	 type of asset
	 */
	unsigned int type;
	/*
	 scene for asset to be loaded to
	 */
	unsigned int scene;
	/*
	 represents whether asset has been loaded or not
	 */
	bool loaded;

	Asset(string Filename, unsigned int Scene) :
			filename(Filename), scene(Scene), loaded(false)
	{
	}

	/*
	 Abstract function, called when the asset is loaded
	 */
	virtual void Load() = 0;
	/*
	 Abstract function, called when the asset is unloaded
	 */
	virtual void Unload() = 0;
};

#endif
