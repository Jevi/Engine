#include "asset_manager.h"

EntityLoader* EntityLoader::instance;

EntityLoader* EntityLoader::GetInstance()
{
	if (!instance)
	{
		instance = new EntityLoader;
	}
	return instance;
}

bool EntityLoader::LoadAssetsFromXML(string Filename)
{
	XMLDocument doc;

	if (doc.LoadFile(Filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log("Could Not Load: %s", Filename.c_str());
		return false;
	}
	Debug::Log("----- Processing: %s -----\n", Filename.c_str());

	XMLNode* Tree = doc.FirstChild();
	if (Tree)
	{
		ProcessElements(Tree);

	}
	vector<Entity*> vec = sceneToEntityVectorMap[0];
	Debug::Log("Total Entities Loaded: %i", vec.size());
	Debug::Log("\n----- Finished Processing: %s -----\n", Filename.c_str());
	return true;
}

void EntityLoader::ProcessElements(const XMLNode* Tree)
{
	for (const XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling())
	{
		const XMLElement* Element = Node->ToElement();
		if (strcmp(Element->Name(), "Entity") == 0)
		{
			ProcessEntity(Node);
		}
		if (strcmp(Element->Name(), "Asset") == 0)
		{
			ProcessAsset(Node);
		}
	}
}

void EntityLoader::ProcessAsset(const XMLNode* AssetNode)
{
	const XMLElement* assetElement = AssetNode->ToElement();
	Asset* asset = 0;
	string filename(assetElement->Attribute("filename"));
	unsigned int type = atoi(assetElement->Attribute("type"));
	unsigned int scene = atoi(assetElement->Attribute("scene"));

	switch (type)
	{
	case Asset::GRAPHICAL:
		asset = new Sprite(filename, scene);
		asset->type = Asset::GRAPHICAL;
		break;
	case Asset::AUDIO:
		break;
	}
	assetMap[scene].push_back(asset);
	Debug::Log("Loaded Asset: %s, %s, %i", asset->filename.c_str(), Asset::TypeToString(asset->type).c_str(), asset->scene);
}

void EntityLoader::ProcessEntity(const XMLNode* EntityNode)
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
		if (entityElement->Attribute("name") == NULL)
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

		name = string((entityElement->Attribute("name")));
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
					if (componentElement->Attribute("name") == NULL)
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

					name = string(componentElement->Attribute("name"));

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
						asset = new Sprite(filename, scene);
						asset->type = Asset::GRAPHICAL;
						break;
					case Asset::AUDIO:
						break;
					}
					assetMap[scene].push_back(asset);
					Debug::Log("Loaded Asset: %s, %s, %i", asset->filename.c_str(), Asset::TypeToString(asset->type).c_str(), asset->scene);
					// 
					switch (type)
					{
					case Component::RENDER:
						component = new RenderComponent(name, (Sprite*) asset, enabled);
						break;
					case Component::AUDIO:
						break;
					}

					Debug::Log("Loaded Component: %s, %s, %s", name.c_str(), Component::TypeToString(type).c_str(), Debug::BoolToString(enabled).c_str());
					entity->AddComponent(component);
				}
				while (0);
			}
		}
		LoadEntity(entity);
	}
	while (0);
}

bool EntityLoader::LoadEntity(Entity* NewEntity)
{
	vector<Entity*> entities = GetEntitiesAtScene(unsigned int(0));
	bool canAdd = true;

	for (int i = 0; i < entities.size(); i++)
	{
		if (strcmp(NewEntity->GetName().c_str(), entities[i]->GetName().c_str()) == 0)
		{
			canAdd = false;
		}
	}
	if (canAdd)
	{
		Debug::Log("Loaded Entity: %s, %f, %f, %f, %f", NewEntity->GetName().c_str(), NewEntity->transform.position.x, NewEntity->transform.position.y, NewEntity->transform.rotation, NewEntity->transform.scale);
		sceneToEntityVectorMap[0].push_back(NewEntity);
	}
	else
	{
		Debug::Log("Could Not Load Entity: %s, %f, %f, %f, %f", NewEntity->GetName().c_str(), NewEntity->transform.position.x, NewEntity->transform.position.y, NewEntity->transform.rotation, NewEntity->transform.scale);
		delete NewEntity;
	}
	return canAdd;
}

unsigned int EntityLoader::GetCurrentScene()
{
	return currentScene;
}

vector<Entity*> EntityLoader::GetEntitiesAtScene(unsigned int Scene)
{
	return sceneToEntityVectorMap[Scene];
}

void EntityLoader::SetCurrentScene(unsigned int Scene)
{
	//If this isn't the first scene load, unload all of the currently loaded assets and change the current scene
	if (currentScene != -1)
	{
		Debug::Log("Unloading Assets From Scene: %i", currentScene);
		vector<Asset*> currentSceneAssetVec = assetMap[currentScene];
		for (unsigned int i = 0; i < currentSceneAssetVec.size(); ++i)
		{
			currentSceneAssetVec[i]->Unload();
		}
	}

	currentScene = Scene;
	Debug::Log("----- Loading Assets For Scene: %i -----\n", currentScene);
	vector<Asset*> vec = assetMap[currentScene];
	//Load all of the new scene's assets
	for (unsigned int i = 0; i < vec.size(); ++i)
	{
		vec[i]->Load();
	}
	Debug::Log("\n----- Finished Loading Assets For Scene: %i -----\n", currentScene);
}

void EntityLoader::Destroy()
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
