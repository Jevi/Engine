#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include <vector>

#include "tinyxml2.h"
#include "entity.h"
#include "asset_system.h"

using namespace std;
using namespace tinyxml2;

class Engine;
class AssetLoader;
class Entity;

class LevelSystem
{
public:

	static LevelSystem* GetInstance();

	void Destroy();

	void LoadLevel(unsigned int Level);

	void LoadNextLevel();

	void LoadPreviousLevel();

	unsigned int GetCurrentLevel()
	{
		return currentLevel;
	}

	void UpdateLevel();

private:

	LevelSystem() :
			currentLevel(0)
	{

	}

	static LevelSystem* instance;
	static AssetLoader* assetLoader;

	unsigned int currentLevel;
	vector<Entity*> entities;

	string GetLevelEntitiesXML(unsigned int Level);
	void ProcessEntity(const XMLNode* EntityNode);
};

#endif
