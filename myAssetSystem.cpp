#include "myAssetSystem.h"

#include "myEngine.h"
#include "myDebug.h"
#include "mySprite.h"
#include "mySpriteSheet.h"

std::vector<std::shared_ptr<myAsset>> myAssetManager::_sharedAssets;

myAssetSystem::myAssetSystem() {

}

std::shared_ptr<myAsset> myAssetSystem::GetAsset(std::string Id) {
	for (auto asset : _sharedAssets) {
		if (strcmp(asset->id.c_str(), Id.c_str()) == 0) {
			return asset;
		}
	}
	return NULL;
}

bool myAssetSystem::LoadAssets() {
	tinyxml2::XMLDocument doc;

	std::string filename = _workspace + "/assets.xml";

	if (doc.LoadFile(filename.c_str()) != tinyxml2::XML_SUCCESS) {
		myDebug::Log(myDebug::LOG_ERROR, "Could Not Load: %s", filename.c_str());
		return false;
	}
	myDebug::Log(myDebug::LOG_ENTRY, "Processing: %s", filename.c_str());

	tinyxml2::XMLNode* Tree = doc.FirstChild();
	if (Tree) {
		ProcessElements(Tree);
	}

	myDebug::Log(myDebug::LOG_INFO, "Total Assets Loaded: %i", _sharedAssets.size());
	myDebug::Log(myDebug::LOG_ENTRY, "Finished Processing: %s", filename.c_str());
	return true;
}

void myAssetSystem::ProcessElements(const tinyxml2::XMLNode* Tree) {
	for (const tinyxml2::XMLNode* Node = Tree->FirstChild(); Node; Node = Node->NextSibling()) {
		const tinyxml2::XMLElement* Element = Node->ToElement();
		if (strcmp(Element->Name(), "Asset") == 0) {
			ProcessAsset(Node);
		}
	}
}

void myAssetSystem::ProcessAsset(const tinyxml2::XMLNode* AssetNode) {
	const tinyxml2::XMLElement* assetElement = AssetNode->ToElement();
	std::string id(assetElement->Attribute("id"));
	std::string filename(assetElement->Attribute("filename"));
	unsigned int type = atoi(assetElement->Attribute("type"));

	switch (type) {
		case myAsset::SPRITE: {
			std::shared_ptr<mySprite> sprite(new mySprite(id, filename));
			_sharedAssets.push_back(sprite);
			myDebug::Log(myDebug::LOG_INFO, "Loaded:\n%s", sprite->ToString().c_str());
		}
			break;
		case myAsset::SPRITE_SHEET: {
			const tinyxml2::XMLElement* spriteSheetElement = assetElement->FirstChild()->ToElement();
			int totalRows = atoi(spriteSheetElement->Attribute("totalRows"));
			int totalColumns = atoi(spriteSheetElement->Attribute("totalColumns"));
			unsigned long update = (unsigned long) atof(spriteSheetElement->Attribute("update"));
			std::shared_ptr<mySpriteSheet> spriteSheet(new mySpriteSheet(id, filename, totalRows, totalColumns, update));
			_sharedAssets.push_back(spriteSheet);
			myDebug::Log(myDebug::LOG_INFO, "Loaded:\n%s", spriteSheet->ToString().c_str());
		}
			break;
	}
}
