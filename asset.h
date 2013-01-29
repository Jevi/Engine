#ifndef ASSET_H
#define ASSET_H

#include <iostream>
using namespace std;

class Asset
{
public:

	// constant types of Assets
    enum AssetType
	{
		GRAPHICAL, AUDIO
	};

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
			default:
				return "DEFAULT";
		}
	}

	string id;
	/*
	 asset location on hdd
	 */
	string filename;
	/*
	 type of asset
	 */
	unsigned int type;
	/*
	 represents whether asset has been loaded or not
	 */
	bool loaded;

	Asset(string Id, string Filename, unsigned int Type) :
			id(Id), filename(Filename), type(Type), loaded(false)
	{
	}

	/*
	 Abstract function, called when the asset is loaded
	 */
	virtual bool Load() = 0;
	/*
	 Abstract function, called when the asset is unloaded
	 */
	virtual void Unload() = 0;

	virtual string ToString() = 0;
};

#endif
