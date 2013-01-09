#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <vector>
#include <map>

#include "asset.h"
#include "debug.h"
#include "tinyxml2.h"
#include "texture2D.h"
#include "entity.h"

using namespace tinyxml2;

class EntityLoader
{
public:

	map<unsigned int, vector<Asset*> > assetMap;
	map<unsigned int, vector<Entity*> > sceneToEntityVectorMap;

	static EntityLoader* GetInstance();

	bool LoadAssetsFromXML(string Filename);
	void ProcessEntities(const XMLNode* Tree);
	void ProcessComponents(const XMLNode* Tree);
	unsigned int GetCurrentScene();
	void SetCurrentScene(unsigned int CurrScene);
	unsigned int GetLoadedAssetCount()
	{
		return loadedAssetCount;
	}
	void Destroy();

private:

	static EntityLoader* instance;
	unsigned int currentScene;
	unsigned int loadedAssetCount;

	EntityLoader() :
			currentScene(-1), loadedAssetCount(0)
	{
	}
};

#endif
