#ifndef ASSETSYSTEM_H
#define ASSETSYSTEM_H

#include <vector>

#include "system.h"
#include "tinyxml2.h"
#include "asset.h"

class AssetSystem : public System{
public:

	static AssetSystem* GetInstance();

	std::vector<Asset*> assets;

	Asset* GetAsset(std::string Id);

	void Destroy();

	bool LoadAssets();

private:

	static AssetSystem* instance;
	unsigned int loadedAssetCount;

	AssetSystem();
	~AssetSystem() {
	}

	void ProcessElements(const tinyxml2::XMLNode* Tree);

	void ProcessAsset(const tinyxml2::XMLNode* AssetNode);

};

#endif
