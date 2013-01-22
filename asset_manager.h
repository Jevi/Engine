#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <vector>
#include <map>

#include "asset.h"
#include "sprite.h"
#include "debug.h"
#include "tinyxml2.h"
#include "entity.h"
#include "render_component.h"

using namespace tinyxml2;

class AssetManager
{
public:

	static AssetManager* GetInstance();

	bool LoadAssetsFromXML(string Filename);

	// Accessors

	/*
	 get current active scene
	 */
	unsigned int GetCurrentScene();
	/*

	 */
	unsigned int GetLoadedAssetCount()
	{
		return loadedAssetCount;
	}

	/*
	 Returns entities at specific scene
	 */
	vector<Entity*> GetEntitiesAtScene(unsigned int Scene);

	// Modifiers

	/*
	 Unload all loaded assets and load assets for new scene
	 */
	void SetCurrentScene(unsigned int Scene);

	/*
	 deletes all assets for all scenes and deletes singleton instance
	 */
	void Destroy();

private:

	static AssetManager* instance;

	unsigned int currentScene;
	unsigned int loadedAssetCount;

	map<unsigned int, vector<Asset*> > assetMap;
	map<unsigned int, vector<Entity*> > sceneToEntityVectorMap;

	AssetManager() :
			currentScene(-1), loadedAssetCount(0)
	{
	}

	/*
	 creates Entities from filename
	 */
	void ProcessElements(const XMLNode* Tree);
	void ProcessEntity(const XMLNode* EntityNode);
	bool LoadEntity(Entity* Entity);
};

#endif
