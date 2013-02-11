#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include <vector>

#include "system.h"
#include "level_manager.h"
#include "asset_manager.h"
#include "tinyxml2.h"

class Entity;

class LevelSystem: public System, public LevelManager, public AssetManager {
public:

	LevelSystem(void);

	~LevelSystem(void);

	void LoadLevel(unsigned int Level);

	void LoadNextLevel();

	void LoadPreviousLevel();

	void UpdateLevel(unsigned long Dt);

	// Lua Accessors

	Entity* GetEntityAt(unsigned int Idx);

	Entity* GetEntity(std::string Id);

	unsigned int GetNumEntity();

private:

	std::string GetLevelEntitiesXML(unsigned int Level);

	std::shared_ptr<Asset> GetAsset(std::string Id);

	void ProcessEntity(const tinyxml2::XMLNode* EntityNode);
};

#endif
