#ifndef MY_LEVELSYSTEM_H
#define MY_LEVELSYSTEM_H

#include <vector>

#include "mySystem.h"
#include "myLevelManager.h"
#include "myAssetManager.h"
#include "tinyxml2.h"

class myEntity;

class myLevelSystem: public mySystem, public myLevelManager, public myAssetManager {
public:

    myLevelSystem(void);

    ~myLevelSystem(void);

	void LoadLevel(unsigned int Level);

	void LoadNextLevel();

	void LoadPreviousLevel();

	void UpdateLevel(unsigned long Dt);

	// Lua Accessors

	myEntity* GetEntityAt(unsigned int Idx);

	myEntity* GetEntity(std::string Id);

	unsigned int GetNumEntity();

private:

	std::string GetLevelEntitiesXML(unsigned int Level);

	std::shared_ptr<myAsset> GetAsset(std::string Id);

	void ProcessEntity(const tinyxml2::XMLNode* EntityNode);
};

#endif
