#include "render_component.h"
#include "physics_component.h"
#include "engine_math.h"
#include "graphics.h"
#include "tinyxml2.h"
#include "debug.h"

RenderComponent::RenderComponent(std::string Id, std::shared_ptr<Sprite> Sprite, bool Enabled) :
		Component(Id, Component::RENDER), sprite(Sprite), spriteSheet(NULL) {
	enabled = Enabled;

	if (enabled) {
		sprite->Load();
	}
}

RenderComponent::RenderComponent(std::string Id, std::shared_ptr<SpriteSheet> Sprite_Sheet, bool Enabled) :
		Component(Id, Component::RENDER), spriteSheet(Sprite_Sheet), updateSpriteSheet(0), sprite(NULL) {
	enabled = Enabled;

	if (enabled) {
		spriteSheet->Load();
	}
}

RenderComponent::~RenderComponent(void) {
	if (sprite != NULL) {
		sprite->Unload();
	}
	else if (spriteSheet != NULL) {
		spriteSheet->Unload();
	}

}

void RenderComponent::Start() {

}

void RenderComponent::Update(unsigned long Dt) {
	Render(Dt);
}

void RenderComponent::Render(unsigned long Dt) {
	/*if (entity->GetComponent("physics") != NULL) {
	 std::shared_ptr<PhysicsComponent> physicsComponent(std::static_pointer_cast < PhysicsComponent > (entity->GetComponent("physics")));
	 if (physicsComponent->body && physicsComponent->synched) {
	 b2Vec2 bodyVerticies[4];
	 b2Vec2 bodyCenter = physicsComponent->body->GetWorldCenter();
	 float rotation = physicsComponent->body->GetAngle();
	 for (unsigned int i = 0; i < 4; i++) {
	 bodyVerticies[i] = ((b2PolygonShape*) (physicsComponent->body->GetFixtureList()->GetShape()))->GetVertex(i);
	 }
	 Graphics::DrawTexture(sprite, bodyVerticies, bodyCenter, rotation);
	 }
	 }
	 else {
	 
	 }*/
	if (sprite != NULL) {
		RenderSprite();
	}
	else if (spriteSheet != NULL) {
		RenderSpriteSheet(Dt);
	}
}

void RenderComponent::RenderSprite() {
	float x = entity->bodyDef.position.x;
	float y = entity->bodyDef.position.y;
	float rotation = entity->bodyDef.angle;
	float scaleX = entity->scale.x;
	float scaleY = entity->scale.y;
	Graphics::DrawTexture(sprite, x, y, rotation, scaleX, scaleY);
}

void RenderComponent::RenderSpriteSheet(unsigned long Dt) {
	/*updateSpriteSheet += Dt;

	 if (updateSpriteSheet > spriteSheet->update)
	 {
	 if (spriteSheet->currentColumn != spriteSheet->totalColumns - 1) {
	 ++spriteSheet->currentColumn;
	 }
	 else {
	 spriteSheet->currentColumn = 0;
	 }
	 updateSpriteSheet = 0;
	 }*/

	float x = entity->bodyDef.position.x;
	float y = entity->bodyDef.position.y;
	float rotation = entity->bodyDef.angle;
	float scaleX = entity->scale.x;
	float scaleY = entity->scale.y;
	Graphics::DrawTexture(spriteSheet, spriteSheet->currentRow, spriteSheet->currentColumn, x, y, rotation, scaleX, scaleY);
}

std::string RenderComponent::ToString() {
	/*tinyxml2::XMLDocument doc;
	 tinyxml2::XMLElement* componentElement = doc.NewElement("Component");
	 componentElement->SetAttribute("id", id.c_str());
	 componentElement->SetAttribute("type", Component::TypeToString(Component::RENDER).c_str());
	 componentElement->SetAttribute("enabled", enabled);

	 tinyxml2::XMLElement* renderElement = doc.NewElement("Render");
	 renderElement->SetAttribute("asset", sprite->id.c_str());

	 componentElement->LinkEndChild(renderElement);
	 doc.LinkEndChild(componentElement);
	 return Debug::XMLDocumentToString(&doc);*/
	return "RENDER_COMPONENT";
}