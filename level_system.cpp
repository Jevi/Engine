#include "level_system.h"

#include "asset_system.h"

#include "engine_math.h"
#include "engine.h"
#include "debug.h"

#include "asset.h"
#include "sprite.h"

#include "component.h"
#include "render_component.h"
#include "physics_component.h"
#include "input_component.h"
#include "script_component.h"

LevelSystem* LevelSystem::instance;

LevelSystem::LevelSystem() :
		currentLevel(0)
{

}

LevelSystem* LevelSystem::GetInstance()
{
	if (!instance)
	{
		instance = new LevelSystem;
	}
	return instance;
}

void LevelSystem::Destroy()
{
	if (instance)
	{
		for (unsigned int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
		}
		delete instance;
		instance = 0;
	}
}

Entity* LevelSystem::GetEntity(std::string Id)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (strcmp(Id.c_str(), entities[i]->GetId().c_str()) == 0)
		{
			return entities[i];
		}
	}
	return NULL;
}

Entity* LevelSystem::GetEntity(unsigned int Idx)
{
	return entities[Idx];
}

void LevelSystem::LoadLevel(unsigned int Level)
{
	if ((currentLevelPath = GetLevelEntitiesXML(Level)).empty())
	{
		return;
	}
	std::string filename = currentLevelPath + "/entities.xml";

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return;
	}
	Debug::Log(Debug::LOG_ENTRY, "Processing: %s", filename.c_str());

	tinyxml2::XMLNode* Tree = doc.FirstChild();
	if (Tree)
	{
		for (const tinyxml2::XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling())
		{
			const tinyxml2::XMLElement* Element = Node->ToElement();
			if (strcmp(Element->Name(), "Entity") == 0)
			{
				ProcessEntity(Node);
			}
		}
	}
	Debug::Log(Debug::LOG_ENTRY, "Finished Processing: %s", filename.c_str());
}

void LevelSystem::ProcessEntity(const tinyxml2::XMLNode* EntityNode)
{
	const tinyxml2::XMLElement* entityElement = EntityNode->ToElement();
	Entity* entity = 0;
	std::string entityId;
	float posx;
	float posy;
	float rot;
	float scaleX;
	float scaleY;
	bool canAdd = true;

	do
	{
		if (entityElement->Attribute("id") == NULL)
		{
			break;
		}
		if (entityElement->Attribute("x") == NULL)
		{
			break;
		}
		if (entityElement->Attribute("y") == NULL)
		{
			break;
		}
		if (entityElement->Attribute("rot") == NULL)
		{
			break;
		}
		if (entityElement->Attribute("scalex") == NULL)
		{
			break;
		}
		if (entityElement->Attribute("scaley") == NULL)
		{
			break;
		}

		entityId = std::string((entityElement->Attribute("id")));
		posx = EngineMath::PixelsToMeters((float) atof(entityElement->Attribute("x")));
		posy = EngineMath::PixelsToMeters((float) atof(entityElement->Attribute("y")));
		rot = (float) atof(entityElement->Attribute("rot"));
		rot = EngineMath::DegreesToRadians(rot);
		scaleX = (float) atof(entityElement->Attribute("scalex"));
		scaleY = (float) atof(entityElement->Attribute("scaley"));

		entity = new Entity(entityId, posx, posy, rot, scaleX, scaleY);

		// Process Components
		for (const tinyxml2::XMLNode* componentNode = EntityNode->FirstChild(); componentNode; componentNode = componentNode->NextSibling())
		{
			const tinyxml2::XMLElement* componentElement = componentNode->ToElement();
			if (strcmp(componentElement->Name(), "Component") == 0)
			{
				Component* component = 0;
				std::string componentId;
				int type;
				bool enabled;

				do
				{
					if (componentElement->Attribute("id") == NULL)
					{
						break;
					}
					if (componentElement->Attribute("type") == NULL)
					{
						break;
					}
					if (componentElement->Attribute("enabled") == NULL)
					{
						break;
					}

					componentId = std::string(componentElement->Attribute("id"));
					type = atoi(componentElement->Attribute("type"));
					enabled = (atoi(componentElement->Attribute("enabled")) != 0);

					switch (type)
					{
						case Component::RENDER:
						{
							const tinyxml2::XMLElement* assetElement = componentNode->FirstChild()->ToElement();
							std::string assetId(assetElement->Attribute("asset"));
							Asset* asset = AssetSystem::GetInstance()->GetAsset(assetId);
							Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", asset->ToString().c_str());
							component = new RenderComponent(componentId, (Sprite*) asset, enabled);
						}
							break;
						case Component::AUDIO:
							break;
						case Component::PHYSICS:
						{
							const tinyxml2::XMLElement* physicsElement = componentNode->FirstChild()->ToElement();
							unsigned int bodyType = atoi(physicsElement->Attribute("type"));
							float density = (float) atof(physicsElement->Attribute("density"));
							float friction = (float) atof(physicsElement->Attribute("friction"));
							float restitution = (float) atof(physicsElement->Attribute("restitution"));
							float gravityScale = (float) atof(physicsElement->Attribute("gravityScale"));
							bool allowSleep = (atoi(physicsElement->Attribute("allowSleep")) != 0);
							component = new PhysicsComponent(componentId, bodyType, enabled);
							((PhysicsComponent*) component)->density = density;
							((PhysicsComponent*) component)->friction = friction;
							((PhysicsComponent*) component)->restitution = restitution;
							((PhysicsComponent*) component)->gravityScale = gravityScale;
							((PhysicsComponent*) component)->allowSleep = allowSleep;
						}
							break;
						case Component::INPUT:
						{
							const tinyxml2::XMLElement* inputElement = componentNode->FirstChild()->ToElement();
							component = new InputComponent(componentId, enabled);
						}
							break;
						case Component::SCRIPT:
						{
							const tinyxml2::XMLElement* scriptElement = componentNode->FirstChild()->ToElement();
							std::string filename(scriptElement->Attribute("filename"));
							component = new ScriptComponent(componentId, filename, enabled);
						}
					}
					if (component)
					{
						entity->AddComponent(component);
						Debug::Log(Debug::LOG_INFO, "Added Component To: %s\n%s", entity->GetId().c_str(), component->ToString().c_str());
					}
				}
				while (0);
			}
		} // process components

		for (unsigned int i = 0; i < entities.size(); i++)
		{
			if (strcmp(entity->GetId().c_str(), entities[i]->GetId().c_str()) == 0)
			{
				canAdd = false;
			}
		}

		if (canAdd)
		{
			Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", entity->ToString().c_str());
			entities.push_back(entity);
		}
		else
		{
			Debug::Log(Debug::LOG_INFO, "Could Not Load:\n%s", entity->ToString().c_str());
			delete entity;
		}
	}
	while (0);
}

void LevelSystem::LoadNextLevel()
{
	LoadLevel(++currentLevel);
}

void LevelSystem::LoadPreviousLevel()
{
	LoadLevel(--currentLevel);
}

std::string LevelSystem::GetLevelEntitiesXML(unsigned int Level)
{
	std::string filename = Engine::GetInstance()->GetAppProject() + "/levels/levels.xml";
	std::string level = Debug::NumberToString(Level);

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return "";
	}

	const tinyxml2::XMLNode* tree = doc.FirstChild();
	if (tree)
	{
		for (const tinyxml2::XMLNode* node = tree->FirstChild(); node; node = node->NextSibling())
		{
			const tinyxml2::XMLElement* element = node->ToElement();
			if (strcmp(element->Name(), "Level") == 0)
			{
				if (strcmp(element->Attribute("num"), level.c_str()) == 0)
				{
					return Engine::GetInstance()->GetAppProject() + "/levels/" + std::string(element->Attribute("id"));
				}
			}
		}
	}
	return "";
}

void LevelSystem::UpdateLevel()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities[i]->Update(0);
	}
}
