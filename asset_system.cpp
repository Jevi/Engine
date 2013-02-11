#include "asset_system.h"

#include "engine.h"
#include "debug.h"
#include "sprite.h"
#include "sprite_sheet.h"

std::vector<std::shared_ptr<Asset>> AssetManager::_sharedAssets;

AssetSystem::AssetSystem() {

}

std::shared_ptr<Asset> AssetSystem::GetAsset(std::string Id) {
	for (auto asset : _sharedAssets) {
		if (strcmp(asset->id.c_str(), Id.c_str()) == 0) {
			return asset;
		}
	}
	return NULL;
}

bool AssetSystem::LoadAssets() {
	tinyxml2::XMLDocument doc;

	std::string filename = _workspace + "/assets.xml";

	if (doc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
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
	std::string id(assetElement->Attribute("id"));
	std::string filename(assetElement->Attribute("filename"));
	unsigned int type = atoi(assetElement->Attribute("type"));

	switch (type) {
		case Asset::SPRITE: {
			std::shared_ptr<Sprite> sprite(new Sprite(id, filename));
			_sharedAssets.push_back(sprite);
			Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", sprite->ToString().c_str());
		}
			break;
		case Asset::SPRITE_SHEET: {
			const tinyxml2::XMLElement* spriteSheetElement = assetElement->FirstChild()->ToElement();
			int totalRows = atoi(spriteSheetElement->Attribute("totalRows"));
			int totalColumns = atoi(spriteSheetElement->Attribute("totalColumns"));
			unsigned long update = (unsigned long) atof(spriteSheetElement->Attribute("update"));
			std::shared_ptr<SpriteSheet> spriteSheet(new SpriteSheet(id, filename, totalRows, totalColumns, update));
			_sharedAssets.push_back(spriteSheet);
			Debug::Log(Debug::LOG_INFO, "Loaded:\n%s", spriteSheet->ToString().c_str());
		}
			break;
	}
}
