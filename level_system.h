#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include <vector>

#include "tinyxml2.h"
#include "entity.h"

class Entity;

class LevelSystem
{
public:

	static LevelSystem* GetInstance();

	void Destroy();

	void LoadLevel(unsigned int Level);

	void LoadNextLevel();

	void LoadPreviousLevel();

	void UpdateLevel();

	// Accessors

	unsigned int GetCurrentLevel()
	{
		return currentLevel;
	}

	std::string GetCurrentLevelPath()
	{
		return currentLevelPath;
	}

	unsigned int GetTotalEntities()
	{
		return entities.size();
	}

	Entity* GetEntity(std::string Id);

	Entity* GetEntity(unsigned int Idx);

private:

	LevelSystem();
	~LevelSystem()
	{
	}

	static LevelSystem* instance;

	unsigned int currentLevel;
	std::string currentLevelPath;
	std::vector<Entity*> entities;

	std::string GetLevelEntitiesXML(unsigned int Level);

	void ProcessEntity(const tinyxml2::XMLNode* EntityNode);
};

#endif
