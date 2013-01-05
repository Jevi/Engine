#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <vector>
#include <map>

#include "Asset.h"
#include "Debug.h"
#include "tinyxml2.h"
#include "Texture2D.h"

using namespace tinyxml2;

class AssetManager
{
public:

	map<unsigned int, vector<Asset*>> assetMap;

	static AssetManager* GetInstance();

	bool LoadAssetsFromXML(string Filename);
	void SetCurrentScene(unsigned int CurrScene);
	unsigned int GetLoadedAssetCount()
	{
		return loadedAssetCount;
	}
	void Destroy();

private:

	static AssetManager* instance;
	unsigned int currentScene;
	unsigned int loadedAssetCount;

	AssetManager() :
			currentScene(-1), loadedAssetCount(0)
	{
	}
};

#endif
