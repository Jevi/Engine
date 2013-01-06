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
	Debug::Log("Loading: %s", Filename.c_str());
	XMLDocument doc;

	if (doc.LoadFile(Filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log("Could Not Load: %s", Filename.c_str());
		return false;
	}
	Debug::Log("Loaded: %s", Filename.c_str());

	XMLNode* AssetTree = doc.FirstChild();
	if (AssetTree)
	{
		Debug::Log("Root Name: %s", AssetTree->ToElement()->Name());
		for (XMLNode* child = AssetTree->FirstChild(); child; child = child->NextSibling())
		{
			XMLElement* Element = child->ToElement();
			if (Element)
			{
				Debug::Log("Current Element: %s", Element->Name());
				Asset* asset = 0;

				string filename(Element->Attribute("filename"));
				string type(Element->Attribute("type"));
				int scene = atoi(Element->Attribute("scene"));

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
		return true;
	}
	return false;
}

unsigned int AssetManager::GetCurrentScene()
{
	return currentScene;
}

void AssetManager::SetCurrentScene(unsigned int CurrScene)
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
}