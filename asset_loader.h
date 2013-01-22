#ifndef ASSETLOADER_H
#define ASSETLOADER_H

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

	vector<Asset*> GetAssets()
	{
		return assets;
	}

	void Destroy();

	bool LoadAssets();

	unsigned int GetLoadedAssetCount()
	{
		return loadedAssetCount;
	}

private:

	static AssetLoader* instance;
	unsigned int loadedAssetCount;
	vector<Asset*> assets;

	AssetLoader() :
			loadedAssetCount(0)
	{
	}

	void ProcessElements(const XMLNode* Tree);
	void ProcessAsset(const XMLNode* AssetNode);

};

#endif
