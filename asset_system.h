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

class AssetSystem
{
public:

	static AssetSystem* GetInstance();

	vector<Asset*> assets;

	Asset* GetAsset(string Id);

	void Destroy();

	bool LoadAssets();

	unsigned int GetLoadedAssetCount()
	{
		return loadedAssetCount;
	}

private:

	static AssetSystem* instance;
	unsigned int loadedAssetCount;

	AssetSystem() :
			loadedAssetCount(0)
	{
	}

	void ProcessElements(const XMLNode* Tree);
	void ProcessAsset(const XMLNode* AssetNode);

};

#endif
