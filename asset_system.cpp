#include "asset_system.h"

#include "engine.h"
#include "debug.h"
#include "sprite.h"

AssetSystem* AssetSystem::instance;

AssetSystem::AssetSystem()
	: loadedAssetCount(0)
{

}

AssetSystem* AssetSystem::GetInstance()
{
	if (!instance)
	{
		instance = new AssetSystem;
	}
	return instance;
}

Asset* AssetSystem::GetAsset( std::string Id)
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

void AssetSystem::Destroy()
{
	if (instance)
	{
		for (unsigned int i = 0; i < assets.size(); ++i)
		{
			delete assets[i];
		}
		delete instance;
		instance = 0;
	}
}

bool AssetSystem::LoadAssets()
{
	tinyxml2::XMLDocument doc;

	 std::string filename = Engine::GetInstance()->GetAppProject() + "/assets.xml";

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return false;
	}
	Debug::Log(Debug::LOG_ENTRY, "Processing: %s", filename.c_str());

	tinyxml2::XMLNode* Tree = doc.FirstChild();
	if (Tree)
	{
		ProcessElements(Tree);
	}

	Debug::Log(Debug::LOG_INFO, "Total Assets Loaded: %i", assets.size());
	Debug::Log(Debug::LOG_ENTRY, "Finished Processing: %s", filename.c_str());
	return true;
}

void AssetSystem::ProcessElements(const tinyxml2::XMLNode* Tree)
{
	for (const tinyxml2::XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling())
	{
		const tinyxml2::XMLElement* Element = Node->ToElement();
		if (strcmp(Element->Name(), "Asset") == 0)
		{
			ProcessAsset(Node);
		}
	}
}

void AssetSystem::ProcessAsset(const tinyxml2::XMLNode* AssetNode)
{
	const tinyxml2::XMLElement* assetElement = AssetNode->ToElement();
	Asset* asset = 0;
	 std::string id(assetElement->Attribute("id"));
	 std::string filename(assetElement->Attribute("filename"));
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
