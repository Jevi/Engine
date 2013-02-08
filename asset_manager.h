#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <vector>
#include <memory>
#include "asset.h"

class AssetManager {
protected:
	static std::vector<std::shared_ptr<Asset> > _sharedAssets;
};

#endif
