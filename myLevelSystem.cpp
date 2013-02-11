#include "myLevelSystem.h"

#include "myAssetSystem.h"

#include "myMath.h"
#include "myEngine.h"
#include "myDebug.h"

#include "myAsset.h"
#include "mySprite.h"
#include "mySpriteSheet.h"

#include "myComponent.h"
#include "myRenderComponent.h"
#include "myPhysicsComponent.h"
#include "myInputComponent.h"
#include "myScriptComponent.h"

unsigned int myLevelManager::_currentLevel = 0;
std::shared_ptr<b2World> myLevelManager::_world;
std::vector<std::shared_ptr<myEntity> > myLevelManager::_sharedEntities;

myLevelSystem::myLevelSystem(void) {

}

myLevelSystem::~myLevelSystem(void) {

}

void myLevelSystem::LoadLevel(unsigned int Level) {
	if ((_currentLevelPath = GetLevelEntitiesXML(Level)).empty()) {
		return;
	}
	std::string filename = _currentLevelPath + "/entities.xml";

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
		myDebug::Log(myDebug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return;
	}
	myDebug::Log(myDebug::LOG_ENTRY, "Processing: %s", filename.c_str());

	tinyxml2::XMLNode* Tree = doc.FirstChild();
	if (Tree) {
		for (const tinyxml2::XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling()) {
			const tinyxml2::XMLElement* Element = Node->ToElement();
			if (strcmp(Element->Name(), "Entity") == 0) {
				ProcessEntity(Node);
			}
		}
	}
	myDebug::Log(myDebug::LOG_ENTRY, "Finished Processing: %s", filename.c_str());
}

void myLevelSystem::ProcessEntity(const tinyxml2::XMLNode* EntityNode) {
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
		posx = myMath::PixelsToMeters((float) atof(entityElement->Attribute("x")));
		posy = myMath::PixelsToMeters((float) atof(entityElement->Attribute("y")));
		rot = (float) atof(entityElement->Attribute("rot"));
		rot = myMath::DegreesToRadians(rot);
		scaleX = (float) atof(entityElement->Attribute("scalex"));
		scaleY = (float) atof(entityElement->Attribute("scaley"));

		std::shared_ptr<myEntity> entity(new myEntity(entityId, posx, posy, rot, scaleX, scaleY));

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
						case myComponent::RENDER: {
							const tinyxml2::XMLElement* assetElement = componentNode->FirstChild()->ToElement();
							std::string assetId(assetElement->Attribute("asset"));
							std::shared_ptr<myAsset> asset = GetAsset(assetId);
							switch (asset->type) {
								case myAsset::SPRITE: {
									myDebug::Log(myDebug::LOG_INFO, "Loaded:\n%s", asset->ToString().c_str());
									std::shared_ptr<myRenderComponent> component(new myRenderComponent(componentId, std::static_pointer_cast < mySprite > (asset), enabled));
									entity->AddComponent(component);
								}
									break;
								case myAsset::SPRITE_SHEET: {
									myDebug::Log(myDebug::LOG_INFO, "Loaded:\n%s", asset->ToString().c_str());
									std::shared_ptr<myRenderComponent> component(new myRenderComponent(componentId, std::static_pointer_cast < mySpriteSheet > (asset), enabled));
									entity->AddComponent(component);
								}
									break;
							}

						}
							break;
						case myComponent::AUDIO:
							break;
						case myComponent::PHYSICS: {
							const tinyxml2::XMLElement* physicsElement = componentNode->FirstChild()->ToElement();
							unsigned int bodyType = atoi(physicsElement->Attribute("type"));
							float density = (float) atof(physicsElement->Attribute("density"));
							float friction = (float) atof(physicsElement->Attribute("friction"));
							float restitution = (float) atof(physicsElement->Attribute("restitution"));
							float gravityScale = (float) atof(physicsElement->Attribute("gravityScale"));
							bool allowSleep = (atoi(physicsElement->Attribute("allowSleep")) != 0);
							std::shared_ptr<myPhysicsComponent> component(new myPhysicsComponent(componentId, bodyType, enabled));
							component->density = density;
							component->friction = friction;
							component->restitution = restitution;
							component->gravityScale = gravityScale;
							component->allowSleep = allowSleep;
							entity->AddComponent(component);
						}
							break;
						case myComponent::INPUT: {
							const tinyxml2::XMLElement* inputElement = componentNode->FirstChild()->ToElement();
							std::shared_ptr<myInputComponent> component(new myInputComponent(componentId, enabled));
							entity->AddComponent(component);
						}
							break;
						case myComponent::SCRIPT: {
							const tinyxml2::XMLElement* scriptElement = componentNode->FirstChild()->ToElement();
							std::string filename(scriptElement->Attribute("filename"));
							std::shared_ptr<myScriptComponent> component(new myScriptComponent(componentId, filename, enabled));
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

		for (auto sharedEntity : _sharedEntities) {
			if (strcmp(entity->GetId().c_str(), sharedEntity->GetId().c_str()) == 0) {
				canAdd = false;
			}
		}

		if (canAdd) {
			myDebug::Log(myDebug::LOG_INFO, "Loaded:\n%s", entity->ToString().c_str());
			_sharedEntities.push_back(entity);
		}
		else {
			myDebug::Log(myDebug::LOG_INFO, "Could Not Load:\n%s", entity->ToString().c_str());
		}
	}
	while (0);
}

void myLevelSystem::LoadNextLevel() {
	LoadLevel(++_currentLevel);
}

void myLevelSystem::LoadPreviousLevel() {
	LoadLevel(--_currentLevel);
}

std::string myLevelSystem::GetLevelEntitiesXML(unsigned int Level) {
	std::string filename = _workspace + "/levels/levels.xml";
	std::string level = myDebug::NumberToString(Level);

	tinyxml2::XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
		myDebug::Log(myDebug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return NULL;
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
	return NULL;
}

void myLevelSystem::UpdateLevel(unsigned long Dt) {
	for (auto entity : _sharedEntities) {
		entity->Update(Dt);
	}
}

std::shared_ptr<myAsset> myLevelSystem::GetAsset(std::string Id) {
	for (auto asset : _sharedAssets) {
		if (strcmp(asset->id.c_str(), Id.c_str()) == 0) {
			return asset;
		}
	}
	return NULL;
}

myEntity* myLevelSystem::GetEntityAt(unsigned int Idx) {
	if (Idx >= 0 && Idx < _sharedEntities.size()) {
		return &*_sharedEntities[Idx];
	}
	return NULL;
}

myEntity* myLevelSystem::GetEntity(std::string Id) {
	for (auto entity : _sharedEntities) {
		if (strcmp(entity->GetId().c_str(), Id.c_str()) == 0) {
			return &*entity;
		}
	}
	return NULL;
}

unsigned int myLevelSystem::GetNumEntity() {
	return _sharedEntities.size();
}
