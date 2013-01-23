#include "asset_manager.h"

AssetManager* AssetManager::instance;

AssetManager* AssetManager::GetInstance()
{
	if (!instance)
	{
		instance = new AssetManager;
	}
	return instance;
}

bool AssetManager::LoadAssetsFromXML(string Filename)
{
	XMLDocument doc;

	if (doc.LoadFile(Filename.c_str()) != XML_SUCCESS)
	{
        Debug::Log(Debug::LOG_WARNING, "Could Not Load: %s", Filename.c_str());
		return false;
	}
    Debug::Log(Debug::LOG_ENTRY, "----- Processing: %s -----\n", Filename.c_str());

	XMLNode* Tree = doc.FirstChild();
	if (Tree)
	{
		ProcessElements(Tree);

	}
	vector<Entity*> vec = sceneToEntityVectorMap[0];
    Debug::Log(Debug::LOG_INFO, "Total Entities Loaded: %i", vec.size());
    Debug::Log(Debug::LOG_ENTRY, "\n----- Finished Processing: %s -----\n", Filename.c_str());
	return true;
}

void AssetManager::ProcessElements(const XMLNode* Tree)
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

void AssetManager::ProcessEntity(const XMLNode* EntityNode)
{
	const XMLElement* entityElement = EntityNode->ToElement();
	Entity* entity = 0;
	string name;
	float posx;
	float posy;
	float rot;
	float scale;

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
		if (entityElement->Attribute("scale") == NULL)
		{
			break;
		}

		name = string((entityElement->Attribute("id")));
		posx = (float) atof(entityElement->Attribute("x"));
		posy = (float) atof(entityElement->Attribute("y"));
		rot = (float) atof(entityElement->Attribute("rot"));
		scale = (float) atof(entityElement->Attribute("scale"));

		entity = new Entity(name, posx, posy, rot, scale);

		// Process Components
		for (const XMLNode* componentNode = EntityNode->FirstChild(); componentNode; componentNode = componentNode->NextSibling())
		{
			const XMLElement* componentElement = componentNode->ToElement();
			if (strcmp(componentElement->Name(), "Component") == 0)
			{
				Component* component = 0;
				string name;
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

					name = string(componentElement->Attribute("id"));
					type = atoi(componentElement->Attribute("type"));
					enabled = (atoi(componentElement->Attribute("enabled")) != 0);

					// Process Asset
					const XMLElement* assetElement = componentNode->FirstChild()->ToElement();
					Asset* asset = 0;
					string filename(assetElement->Attribute("filename"));
					unsigned int type = atoi(assetElement->Attribute("type"));
					unsigned int scene = atoi(assetElement->Attribute("scene"));

					switch (type)
					{
						case Asset::GRAPHICAL:
							asset = new Sprite("test", "test2");
							break;
						case Asset::AUDIO:
							break;
					}
					assetMap[scene].push_back(asset);
                    Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", asset->ToString().c_str());
					// 
					switch (type)
					{
						case Component::RENDER:
							component = new RenderComponent(name, (Sprite*) asset, enabled);
							break;
						case Component::AUDIO:
							break;
					}
					entity->AddComponent(component);
				}
				while (0);
			}
		}
		LoadEntity(entity);
	}
	while (0);
}

bool AssetManager::LoadEntity(Entity* NewEntity)
{
	vector<Entity*> entities = GetEntitiesAtScene(0);
	bool canAdd = true;

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (strcmp(NewEntity->GetName().c_str(), entities[i]->GetName().c_str()) == 0)
		{
			canAdd = false;
		}
	}
	if (canAdd)
	{
		Debug::Log("Loaded:\n%s", NewEntity->ToString().c_str());
		sceneToEntityVectorMap[0].push_back(NewEntity);
	}
	else
	{
		Debug::Log("Could Not Load:\n%s", NewEntity->ToString().c_str());
		delete NewEntity;
	}
	return canAdd;
}

unsigned int AssetManager::GetCurrentScene()
{
	return currentScene;
}

vector<Entity*> AssetManager::GetEntitiesAtScene(unsigned int Scene)
{
	return sceneToEntityVectorMap[Scene];
}

void AssetManager::SetCurrentScene(unsigned int Scene)
{
	//If this isn't the first scene load, unload all of the currently loaded assets and change the current scene
	if (currentScene != -1)
	{
		Debug::Log("Unloading Assets From Scene: %i", currentScene);
		vector<Asset*> currentSceneAssetVec = assetMap[currentScene];
		for (unsigned int i = 0; i < currentSceneAssetVec.size(); ++i)
		{
			Debug::Log("Unloaded From Scene:\n%s", currentSceneAssetVec[i]->ToString().c_str());
			currentSceneAssetVec[i]->Unload();
		}
	}

	currentScene = Scene;
	Debug::Log("----- Loading Assets For Scene: %i -----\n", currentScene);

	vector<Asset*> currentSceneAssetVec = assetMap[currentScene];
	//Load all of the new scene's assets
	for (unsigned int i = 0; i < currentSceneAssetVec.size(); ++i)
	{
		if (currentSceneAssetVec[i]->Load())
		{
			Debug::Log("Loaded To Scene:\n%s", currentSceneAssetVec[i]->ToString().c_str());
		}
		else
		{
			Debug::Log("Could Not Load To Scene:\n%s", currentSceneAssetVec[i]->ToString().c_str());
		}
	}
	Debug::Log("\n----- Finished Loading Assets For Scene: %i -----\n", currentScene);
}

void AssetManager::Destroy()
{
	map<unsigned int, vector<Asset*> >::iterator pos;
	for (pos = assetMap.begin(); pos != assetMap.end(); ++pos)
	{
		vector<Asset*> assets = pos->second;
		unsigned int size = assets.size();
		for (unsigned int i = 0; i < size; ++i)
		{
			delete assets[i];
		}
	}
	delete this;
}
