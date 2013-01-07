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
	Debug::Log("Loading: %s", Filename.c_str());
	XMLDocument doc;

	if (doc.LoadFile(Filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log("Could Not Load: %s", Filename.c_str());
		return false;
	}
	Debug::Log("Loaded: %s", Filename.c_str());

	XMLNode* Tree = doc.FirstChild();
	if (Tree)
	{
		ProcessEntities(Tree);

	}

	Debug::Log("Loaded Entities: ");
	vector<Entity*> vec = sceneToEntityVectorMap[1];
	for (unsigned int i = 0; i < vec.size(); ++i)
	{
		Debug::Log("Name: %s", vec[i]->GetName().c_str());
	}
	return false;
}

void EntityLoader::ProcessEntities(const XMLNode* Tree)
{
	for (const XMLNode* entityNode = Tree->FirstChild(); entityNode; entityNode = entityNode->NextSibling())
	{
		const XMLElement* entityElement = entityNode->ToElement();
		if (strcmp(entityElement->Name(), "Entity") == 0)
		{
			Entity* entity;
			string name;
			float posx;
			float posy;
			float rot;
			float scale;
			unsigned int scene;

			if (entityElement->Attribute("name") != NULL)
			{
				name = string((entityElement->Attribute("name")));
				if (entityElement->Attribute("posx") != NULL)
				{
					posx = (float) atoi(entityElement->Attribute("posx"));
					if (entityElement->Attribute("posy") != NULL)
					{
						posy = (float) atoi(entityElement->Attribute("posy"));
						if (entityElement->Attribute("rot") != NULL)
						{
							rot = (float) atoi(entityElement->Attribute("rot"));
							if (entityElement->Attribute("scale") != NULL)
							{
								scale = (float) atoi(entityElement->Attribute("scale"));
								if (entityElement->Attribute("scene") != NULL)
								{
									scene = atoi(entityElement->Attribute("scene"));

									entity = new Entity(name, posx, posy, rot, scale);
									Debug::Log("Adding Entity Named: %s", entity->GetName().c_str());
									// should check if entity name is already in use
									sceneToEntityVectorMap[scene].push_back(entity);
									ProcessComponents(entityNode);
								}
							}
						}
					}
				}
			}
		}
	}
	/*const XMLElement* currElem = Parent->ToElement();
	if (currElem)
	{
	Debug::Log("Current Element: %s", currElem->Name());

	if (currElem->Name() == "Entity")
	{
	Entity* entity;
	string name(currElem->Attribute("name"));
	float posx = atoi(currElem->Attribute("posx"));
	float posy = atoi(currElem->Attribute("posy"));
	float rot = atoi(currElem->Attribute("rot"));
	float scale = atoi(currElem->Attribute("scale"));
	entity = new Entity(name, posx, posy, rot, scale);

	Asset* asset = 0;

	string filename(currElem->Attribute("filename"));
	string type(currElem->Attribute("type"));
	int scene = atoi(currElem->Attribute("scene"));

	Debug::Log("Element Values: %s | %s | %i", filename.c_str(), type.c_str(), scene);

	if (type == "GRAPHICAL")
	{
	asset = new Texture2D(filename, scene);
	asset->type = Asset::GRAPHICAL;
	}

	if (asset)
	{
	asset->loaded = true;
	assetMap[asset->scene].push_back(asset);
	++loadedAssetCount;
	Debug::Log("Asset Loaded: %s", filename.c_str());
	}
	}
	}

	for (const XMLNode* child = Parent->FirstChild(); child; child = child->NextSibling())
	{
	Debug::Log("Current Element: %s", child->ToElement()->Name());
	ProcessEntities(child);
	}*/
}

void EntityLoader::ProcessComponents(const XMLNode* Tree)
{
	for (const XMLNode* componentNode = Tree->FirstChild(); componentNode; componentNode = componentNode->NextSibling())
	{
		const XMLElement* componentElement = componentNode->ToElement();
	}
}

unsigned int EntityLoader::GetCurrentScene()
{
	return currentScene;
}

void EntityLoader::SetCurrentScene(unsigned int CurrScene)
{
	//If this isn't the first scene load, unload all of the currently loaded assets and change the current scene
	if (currentScene != -1)
	{
		vector<Asset*> currentSceneAssetVec = assetMap[currentScene];
		for (unsigned int i = 0; i < currentSceneAssetVec.size(); ++i)
		{
			currentSceneAssetVec[i]->OnUnload();
		}
	}

	currentScene = CurrScene;

	vector<Asset*> vec = assetMap[currentScene];
	//Load all of the new scene's assets
	for (unsigned int i = 0; i < vec.size(); ++i)
	{
		vec[i]->OnLoad();
	}

	Debug::Log("Current Scene: %i", currentScene);
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