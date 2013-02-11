#ifndef MY_ASSET_MANAGER_H
#define MY_ASSET_MANAGER_H

#include <vector>
#include <memory>
#include "myAsset.h"

class myAssetManager {
protected:
    static std::vector<std::shared_ptr<myAsset> > _sharedAssets;
};

#endif
