#include "asset_system.h"

AssetLoader* AssetLoader::instance;

AssetLoader* AssetLoader::GetInstance()
{
	if (!instance)
	{
		instance = new AssetLoader;
	}
	return instance;
}

Asset* AssetLoader::GetAsset(string Id)
{
	for (unsigned int i = 0; i < assets.size(); i++)
	{
		if (strcmp(assets[i]->id.c_str(), Id.c_str()) == 0)
		{
			return assets[i];
		}
	}
	return NULL;
}

void AssetLoader::Destroy()
{
	for (unsigned int i = 0; i < assets.size(); ++i)
	{
		delete assets[i];
	}
	delete this;
}

bool AssetLoader::LoadAssets()
{
	XMLDocument doc;

	string filename = Engine::GetProject() + "/assets.xml";

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return false;
	}
	Debug::Log(Debug::LOG_ENTRY, "Processing: %s", filename.c_str());

	XMLNode* Tree = doc.FirstChild();
	if (Tree)
	{
		ProcessElements(Tree);
	}

	Debug::Log(Debug::LOG_INFO, "Total Assets Loaded: %i", assets.size());
	Debug::Log(Debug::LOG_ENTRY, "Finished Processing: %s", filename.c_str());
	return true;
}

void AssetLoader::ProcessElements(const XMLNode* Tree)
{
	for (const XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling())
	{
		const XMLElement* Element = Node->ToElement();
		if (strcmp(Element->Name(), "Asset") == 0)
		{
			ProcessAsset(Node);
		}
	}
}

void AssetLoader::ProcessAsset(const XMLNode* AssetNode)
{
	const XMLElement* assetElement = AssetNode->ToElement();
	Asset* asset = 0;
	string id(assetElement->Attribute("id"));
	string filename(assetElement->Attribute("filename"));
	unsigned int type = atoi(assetElement->Attribute("type"));

	switch (type)
	{
		case Asset::GRAPHICAL:
			asset = new Sprite(id, filename);
			break;
		case Asset::AUDIO:
			break;
	}
	assets.push_back(asset);
	Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", asset->ToString().c_str());
}