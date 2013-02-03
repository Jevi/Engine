#include "level_system.h"
#include "engine_math.h"
#include "engine.h"
#include "debug.h"
#include "render_component.h"
#include "component.h"
#include "asset.h"
#include "sprite.h"
#include "physics_component.h"
#include "input_component.h"
#include "script_component.h"

LevelSystem* LevelSystem::instance;
AssetSystem* LevelSystem::assetLoader;

LevelSystem* LevelSystem::GetInstance()
{
	if (!instance)
	{
		assetLoader = AssetSystem::GetInstance();
		instance = new LevelSystem;
	}
	return instance;
}

Entity* LevelSystem::GetEntity(string Id)
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (strcmp(Id.c_str(), entities[i]->GetId().c_str()) == 0)
		{
			return entities[i];
		}
	}
}

Entity* LevelSystem::GetEntity(unsigned int Idx)
{
	return entities[Idx];
}

void LevelSystem::Destroy()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
	delete this;
}

void LevelSystem::LoadLevel(unsigned int Level)
{
	string levelPath;
	if ((levelPath = GetLevelEntitiesXML(Level)).empty())
	{
		return;
	}
	string filename = levelPath + "/entities.xml";

	XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return;
	}
	Debug::Log(Debug::LOG_ENTRY, "Processing: %s", filename.c_str());

	XMLNode* Tree = doc.FirstChild();
	if (Tree)
	{
		for (const XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling())
		{
			const XMLElement* Element = Node->ToElement();
			if (strcmp(Element->Name(), "Entity") == 0)
			{
				ProcessEntity(Node);
			}
		}
	}
	Debug::Log(Debug::LOG_ENTRY, "Finished Processing: %s", filename.c_str());
}

void LevelSystem::ProcessEntity(const XMLNode* EntityNode)
{
	const XMLElement* entityElement = EntityNode->ToElement();
	Entity* entity = 0;
	string entityId;
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

		entityId = string((entityElement->Attribute("id")));
		posx = EngineMath::PixelsToMeters((float) atof(entityElement->Attribute("x")));
		posy = EngineMath::PixelsToMeters((float) atof(entityElement->Attribute("y")));
		rot = (float) atof(entityElement->Attribute("rot"));
		rot = EngineMath::DegreesToRadians(rot);
		scaleX = (float) atof(entityElement->Attribute("scalex"));
		scaleY = (float) atof(entityElement->Attribute("scaley"));

		entity = new Entity(entityId, posx, posy, rot, scaleX, scaleY);

		// Process Components
		for (const XMLNode* componentNode = EntityNode->FirstChild(); componentNode; componentNode = componentNode->NextSibling())
		{
			const XMLElement* componentElement = componentNode->ToElement();
			if (strcmp(componentElement->Name(), "Component") == 0)
			{
				Component* component = 0;
				string componentId;
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

					componentId = string(componentElement->Attribute("id"));
					type = atoi(componentElement->Attribute("type"));
					enabled = (atoi(componentElement->Attribute("enabled")) != 0);

					switch (type)
					{
						case Component::RENDER:
						{
							const XMLElement* assetElement = componentNode->FirstChild()->ToElement();
							string assetId(assetElement->Attribute("asset"));
							Asset* asset = assetLoader->GetAsset(assetId);
							Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", asset->ToString().c_str());
							component = new RenderComponent(componentId, (Sprite*) asset, enabled);
						}
							break;
						case Component::AUDIO:
							break;
						case Component::PHYSICS:
						{
							const XMLElement* physicsElement = componentNode->FirstChild()->ToElement();
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
							const XMLElement* inputElement = componentNode->FirstChild()->ToElement();
							component = new InputComponent(componentId, enabled);
						}
							break;
						case Component::SCRIPT:
						{
							const XMLElement* scriptElement = componentNode->FirstChild()->ToElement();
							string filename(scriptElement->Attribute("filename"));
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

string LevelSystem::GetLevelEntitiesXML(unsigned int Level)
{
	string filename = Engine::GetInstance()->GetAppProject() + "/levels/levels.xml";
	string level = Debug::NumberToString(Level);

	XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return "";
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
					return Engine::GetInstance()->GetAppProject() + "/levels/" + string(element->Attribute("id"));
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
