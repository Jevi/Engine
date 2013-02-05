#ifndef ASSET_H
#define ASSET_H

#include <iostream>

class Asset {
public:

	// constant types of Assets
	enum AssetType {
		GRAPHICAL, AUDIO
	};

	static std::string TypeToString(unsigned int Type) {
		switch (Type) {
			case GRAPHICAL:
				return std::string("GRAPHICAL");
				break;
			case AUDIO:
				return std::string("AUDIO");
				break;
			default:
				return "DEFAULT";
		}
	}

	std::string id;
	/*
	 asset location on hdd
	 */
	std::string filename;
	/*
	 type of asset
	 */
	unsigned int type;
	/*
	 represents whether asset has been loaded or not
	 */
	bool loaded;

	Asset(std::string Id, std::string Filename, unsigned int Type) :
			id(Id), filename(Filename), type(Type), loaded(false) {
	}

	/*
	 Abstract function, called when the asset is loaded
	 */
	virtual bool Load() = 0;
	/*
	 Abstract function, called when the asset is unloaded
	 */
	virtual void Unload() = 0;

	virtual std::string ToString() = 0;
};

#endif
