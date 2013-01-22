#include "level_manager.h"

#include "engine.h"
#include "tinyxml2.h"
#include "debug.h"

LevelManager* LevelManager::instance;

LevelManager* LevelManager::GetInstance()
{
	if (!instance)
	{
		instance = new LevelManager;
	}
	return instance;
}

void LevelManager::Destroy()
{

}

void LevelManager::LoadLevel(int Level)
{
	string filename = GetLevelEntitiesXML(Level) + "/entities.xml";
}

void LevelManager::LoadNextLevel()
{
	LoadLevel(++currentLevel);
}

void LevelManager::LoadPreviousLevel()
{
	LoadLevel(--currentLevel);
}

string LevelManager::GetLevelEntitiesXML(int Level)
{
	string filename = Engine::GetProject() + "/levels/levels.xml";
	string level = Debug::NumberToString(Level);

	XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log("Could Not Load: %s", filename.c_str());
		return NULL;
	}

	const XMLNode* tree = doc.FirstChild();
	if (tree)
	{
		for (const XMLNode* node = tree->FirstChild(); node; node = node->NextSibling())
		{
			const XMLElement* element = node->ToElement();
			if (strcmp(element->Name(), "Level") == 0)
			{
				if (strcmp(element->Attribute("num"), level.c_str()) == 0)
				{
					return Engine::GetProject() + "/levels/" + string(element->Attribute("id"));
				}
			}
		}
	}
	return NULL;
}