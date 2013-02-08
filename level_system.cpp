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

unsigned int LevelManager::_currentLevel = 0;
std::shared_ptr<b2World> LevelManager::_world;
std::vector<std::shared_ptr<Entity> > LevelManager::_sharedEntities;

LevelSystem::LevelSystem(void) {

}

LevelSystem::~LevelSystem(void) {

}

void LevelSystem::LoadLevel(unsigned int Level) {
	if ((_currentLevelPath = GetLevelEntitiesXML(Level)).empty()) {
		return;
	}
	std::string filename = _currentLevelPath + "/entities.xml";

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS) {
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return;
	}
	Debug::Log(Debug::LOG_ENTRY, "Processing: %s", filename.c_str());

	tinyxml2::XMLNode* Tree = doc.FirstChild();
	if (Tree) {
		for (const tinyxml2::XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling()) {
			const tinyxml2::XMLElement* Element = Node->ToElement();
			if (strcmp(Element->Name(), "Entity") == 0) {
				ProcessEntity(Node);
			}
		}
	}
	Debug::Log(Debug::LOG_ENTRY, "Finished Processing: %s", filename.c_str());
}

void LevelSystem::ProcessEntity(const tinyxml2::XMLNode* EntityNode) {
	const tinyxml2::XMLElement* entityElement = EntityNode->ToElement();
	std::string entityId;
	float posx;
	float posy;
	float rot;
	float scaleX;
	float scaleY;
	bool canAdd = true;

	do {
		if (entityElement->Attribute("id") == NULL) {
			break;
		}
		if (entityElement->Attribute("x") == NULL) {
			break;
		}
		if (entityElement->Attribute("y") == NULL) {
			break;
		}
		if (entityElement->Attribute("rot") == NULL) {
			break;
		}
		if (entityElement->Attribute("scalex") == NULL) {
			break;
		}
		if (entityElement->Attribute("scaley") == NULL) {
			break;
		}

		entityId = std::string((entityElement->Attribute("id")));
		posx = EngineMath::PixelsToMeters((float) atof(entityElement->Attribute("x")));
		posy = EngineMath::PixelsToMeters((float) atof(entityElement->Attribute("y")));
		rot = (float) atof(entityElement->Attribute("rot"));
		rot = EngineMath::DegreesToRadians(rot);
		scaleX = (float) atof(entityElement->Attribute("scalex"));
		scaleY = (float) atof(entityElement->Attribute("scaley"));

		std::shared_ptr<Entity> entity(new Entity(entityId, posx, posy, rot, scaleX, scaleY));

		// Process Components
		for (const tinyxml2::XMLNode* componentNode = EntityNode->FirstChild(); componentNode; componentNode = componentNode->NextSibling()) {
			const tinyxml2::XMLElement* componentElement = componentNode->ToElement();
			if (strcmp(componentElement->Name(), "Component") == 0) {
				std::string componentId;
				int type;
				bool enabled;

				do {
					if (componentElement->Attribute("id") == NULL) {
						break;
					}
					if (componentElement->Attribute("type") == NULL) {
						break;
					}
					if (componentElement->Attribute("enabled") == NULL) {
						break;
					}

					componentId = std::string(componentElement->Attribute("id"));
					type = atoi(componentElement->Attribute("type"));
					enabled = (atoi(componentElement->Attribute("enabled")) != 0);

					switch (type) {
						case Component::RENDER: {
							const tinyxml2::XMLElement* assetElement = componentNode->FirstChild()->ToElement();
							std::string assetId(assetElement->Attribute("asset"));
							std::shared_ptr<Asset> asset = GetAsset(assetId);
							Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", asset->ToString().c_str());
							std::shared_ptr<RenderComponent> component(new RenderComponent(componentId, std::static_pointer_cast < Sprite > (asset), enabled));
							entity->AddComponent(component);
						}
							break;
						case Component::AUDIO:
							break;
						case Component::PHYSICS: {
							const tinyxml2::XMLElement* physicsElement = componentNode->FirstChild()->ToElement();
							unsigned int bodyType = atoi(physicsElement->Attribute("type"));
							float density = (float) atof(physicsElement->Attribute("density"));
							float friction = (float) atof(physicsElement->Attribute("friction"));
							float restitution = (float) atof(physicsElement->Attribute("restitution"));
							float gravityScale = (float) atof(physicsElement->Attribute("gravityScale"));
							bool allowSleep = (atoi(physicsElement->Attribute("allowSleep")) != 0);
							std::shared_ptr<PhysicsComponent> component(new PhysicsComponent(componentId, bodyType, enabled));
							component->density = density;
							component->friction = friction;
							component->restitution = restitution;
							component->gravityScale = gravityScale;
							component->allowSleep = allowSleep;
							entity->AddComponent(component);
						}
							break;
						case Component::INPUT: {
							const tinyxml2::XMLElement* inputElement = componentNode->FirstChild()->ToElement();
							std::shared_ptr<InputComponent> component(new InputComponent(componentId, enabled));
							entity->AddComponent(component);
						}
							break;
						case Component::SCRIPT: {
							const tinyxml2::XMLElement* scriptElement = componentNode->FirstChild()->ToElement();
							std::string filename(scriptElement->Attribute("filename"));
							std::shared_ptr<ScriptComponent> component(new ScriptComponent(componentId, filename, enabled));
							entity->AddComponent(component);
						}
					}
					/*if (component) {
					 entity->AddComponent(component);
					 Debug::Log(Debug::LOG_INFO, "Added Component To: %s\n%s", entity->GetId().c_str(), component->ToString().c_str());
					 }*/
				}
				while (0);
			}
		} // process components

		for (unsigned int i = 0; i < _sharedEntities.size(); i++) {
			if (strcmp(entity->GetId().c_str(), _sharedEntities[i]->GetId().c_str()) == 0) {
				canAdd = false;
			}
		}

		if (canAdd) {
			Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", entity->ToString().c_str());
			_sharedEntities.push_back(entity);
		}
		else {
			Debug::Log(Debug::LOG_INFO, "Could Not Load:\n%s", entity->ToString().c_str());
		}
	}
	while (0);
}

void LevelSystem::LoadNextLevel() {
	LoadLevel(++_currentLevel);
}

void LevelSystem::LoadPreviousLevel() {
	LoadLevel(--_currentLevel);
}

std::string LevelSystem::GetLevelEntitiesXML(unsigned int Level) {
	std::string filename = _workspace + "/levels/levels.xml";
	std::string level = Debug::NumberToString(Level);

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS) {
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return "";
	}

	const tinyxml2::XMLNode* tree = doc.FirstChild();
	if (tree) {
		for (const tinyxml2::XMLNode* node = tree->FirstChild(); node; node = node->NextSibling()) {
			const tinyxml2::XMLElement* element = node->ToElement();
			if (strcmp(element->Name(), "Level") == 0) {
				if (strcmp(element->Attribute("num"), level.c_str()) == 0) {
					return _workspace + "/levels/" + std::string(element->Attribute("id"));
				}
			}
		}
	}
	return "";
}

void LevelSystem::UpdateLevel() {
	for (unsigned int i = 0; i < _sharedEntities.size(); i++) {
		_sharedEntities[i]->Update(0);
	}
}

std::shared_ptr<Asset> LevelSystem::GetAsset(std::string Id) {
	for (unsigned int i = 0; i < _sharedAssets.size(); i++) {
		if (strcmp(_sharedAssets[i]->id.c_str(), Id.c_str()) == 0) {
			return _sharedAssets[i];
		}
	}
	return NULL;
}
