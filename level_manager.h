#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <vector>

#include "engine.h"
#include "tinyxml2.h"
#include "debug.h"
#include "entity.h"
#include "render_component.h"
#include "component.h"
#include "asset.h"
#include "sprite.h"

using namespace std;
using namespace tinyxml2;

class Engine;

class LevelManager
{
public:

	static LevelManager* GetInstance();

	void Destroy();

	void LoadLevel(int Level);

	void LoadNextLevel();

	void LoadPreviousLevel();

	int GetCurrentLevel()
	{
		return currentLevel;
	}

private:

	LevelManager() :
			currentLevel(0)
	{

	}

	static LevelManager* instance;

	int currentLevel;
	vector<Entity*> entities;

	string GetLevelEntitiesXML(int Level);
    void ProcessEntity(const XMLNode* EntityNode);
};

#endif
