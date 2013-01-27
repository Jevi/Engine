#ifndef ASSETSYSTEM_H
#define ASSETSYSTEM_H

#include <vector>

#include "tinyxml2.h"
#include "asset.h"
#include "sprite.h"
#include "engine.h"

using namespace tinyxml2;
using namespace std;

class Engine;

class AssetLoader
{
public:

	static AssetLoader* GetInstance();

	vector<Asset*> assets;

	Asset* GetAsset(string Id);

	void Destroy();

	bool LoadAssets();

	unsigned int GetLoadedAssetCount()
	{
		return loadedAssetCount;
	}

private:

	static AssetLoader* instance;
	unsigned int loadedAssetCount;

	AssetLoader() :
			loadedAssetCount(0)
	{
	}

	void ProcessElements(const XMLNode* Tree);
	void ProcessAsset(const XMLNode* AssetNode);

};

#endif
