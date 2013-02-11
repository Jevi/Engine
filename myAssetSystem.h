#ifndef MY_ASSETSYSTEM_H
#define MY_ASSETSYSTEM_H

#include "mySystem.h"
#include "myAssetManager.h"
#include "tinyxml2.h"

class myAssetSystem: public mySystem, public myAssetManager {
public:

    myAssetSystem(void);
    ~myAssetSystem(void) {
	}

    std::shared_ptr<myAsset> GetAsset(std::string Id);

	bool LoadAssets();

private:

	void ProcessElements(const tinyxml2::XMLNode* Tree);

	void ProcessAsset(const tinyxml2::XMLNode* AssetNode);

};

#endif
