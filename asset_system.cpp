#include "asset_system.h"

#include "engine.h"
#include "debug.h"
#include "sprite.h"

std::vector<std::shared_ptr<Asset>> AssetManager::_sharedAssets;

AssetSystem::AssetSystem() {

}

std::shared_ptr<Asset> AssetSystem::GetAsset(std::string Id) {
	for (unsigned int i = 0; i < _sharedAssets.size(); i++) {
		if (strcmp(_sharedAssets[i]->id.c_str(), Id.c_str()) == 0) {
			return _sharedAssets[i];
		}
	}
	return NULL;
}

bool AssetSystem::LoadAssets() {
	tinyxml2::XMLDocument doc;

	std::string filename = _workspace + "/assets.xml";

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS) {
		Debug::Log(Debug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return false;
	}
	Debug::Log(Debug::LOG_ENTRY, "Processing: %s", filename.c_str());

	tinyxml2::XMLNode* Tree = doc.FirstChild();
	if (Tree) {
		ProcessElements(Tree);
	}

	Debug::Log(Debug::LOG_INFO, "Total Assets Loaded: %i", _sharedAssets.size());
	Debug::Log(Debug::LOG_ENTRY, "Finished Processing: %s", filename.c_str());
	return true;
}

void AssetSystem::ProcessElements(const tinyxml2::XMLNode* Tree) {
	for (const tinyxml2::XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling()) {
		const tinyxml2::XMLElement* Element = Node->ToElement();
		if (strcmp(Element->Name(), "Asset") == 0) {
			ProcessAsset(Node);
		}
	}
}

void AssetSystem::ProcessAsset(const tinyxml2::XMLNode* AssetNode) {
	const tinyxml2::XMLElement* assetElement = AssetNode->ToElement();
	Asset* asset = 0;
	std::string id(assetElement->Attribute("id"));
	std::string filename(assetElement->Attribute("filename"));
	unsigned int type = atoi(assetElement->Attribute("type"));

	switch (type) {
		case Asset::GRAPHICAL:
			asset = new Sprite(id, filename);
			break;
		case Asset::AUDIO:
			break;
	}
	_sharedAssets.push_back(std::unique_ptr < Asset > (asset));
	Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", asset->ToString().c_str());
}
