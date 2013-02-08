#ifndef ASSETSYSTEM_H
#define ASSETSYSTEM_H

#include "system.h"
#include "asset_manager.h"
#include "tinyxml2.h"

class AssetSystem: public System, public AssetManager {
public:

	AssetSystem(void);
	~AssetSystem(void) {
	}

	std::shared_ptr<Asset> GetAsset(std::string Id);

	bool LoadAssets();

private:

	void ProcessElements(const tinyxml2::XMLNode* Tree);

	void ProcessAsset(const tinyxml2::XMLNode* AssetNode);

};

#endif
