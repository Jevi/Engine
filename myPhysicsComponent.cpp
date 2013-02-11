#include "myPhysicsComponent.h"
#include "myGraphics.h"
#include "myDebug.h"
#include "myEngine.h"
#include "myMath.h"
#include "myRenderComponent.h"
#include "tinyxml2.h"

myPhysicsComponent::myPhysicsComponent(std::string Id, unsigned int BodyType, bool Enabled) :
		myComponent(Id, myComponent::PHYSICS), bodyType(BodyType), synched(false), density(1.0f), friction(1.0f), restitution(1.0f), allowSleep(true) {
	enabled = Enabled;
}

myPhysicsComponent::~myPhysicsComponent(void) {
	_world->DestroyBody(body);
}

void myPhysicsComponent::Start() {

}

void myPhysicsComponent::Update(unsigned long Dt) {
	if (!synched) {

		switch (bodyType) {
			case StaticBody:
				entity->bodyDef.type = b2_staticBody;
				break;
			case DynamicBody:
				entity->bodyDef.type = b2_dynamicBody;
		}
		entity->bodyDef.gravityScale = gravityScale;
		entity->bodyDef.allowSleep = allowSleep;
		body = _world->CreateBody(&entity->bodyDef);
		b2PolygonShape shape;
		std::shared_ptr<myRenderComponent> renderComponent(std::static_pointer_cast < myRenderComponent > (entity->GetComponent("render")));
		int width = renderComponent->GetSprite()->width;
		int height = renderComponent->GetSprite()->height;
		shape.SetAsBox(myMath::PixelsToMeters(((float) width) * entity->scale.x) / 2.0f, myMath::PixelsToMeters(((float) height) * entity->scale.y) / 2.0f);

		b2FixtureDef FixtureDef;
		FixtureDef.shape = &shape;
		FixtureDef.density = density;
		FixtureDef.friction = friction;
		FixtureDef.restitution = restitution;
		body->CreateFixture(&FixtureDef);
		synched = true;
	}

	// Debug::Log(Debug::LOG_DEBUG, "%s Awake State: %s - Allow Sleep: %s ", entity->GetId().c_str(), Debug::BoolToString(body->IsAwake()).c_str(), Debug::BoolToString(allowSleep).c_str());
	entity->bodyDef.position.x = body->GetTransform().p.x;
	entity->bodyDef.position.y = body->GetTransform().p.y;
	entity->bodyDef.angle = body->GetTransform().q.GetAngle();
}

std::string myPhysicsComponent::ToString() {
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* componentElement = doc.NewElement("Component");
	componentElement->SetAttribute("id", id.c_str());
	componentElement->SetAttribute("type", myComponent::TypeToString(myComponent::PHYSICS).c_str());
	componentElement->SetAttribute("enabled", enabled);
	tinyxml2::XMLElement* physicsElement = doc.NewElement("Physics");
	physicsElement->SetAttribute("type", bodyType);
	physicsElement->SetAttribute("density", density);
	physicsElement->SetAttribute("friction", friction);
	physicsElement->SetAttribute("restitution", restitution);

	componentElement->LinkEndChild(physicsElement);
	doc.LinkEndChild(componentElement);
	return myDebug::XMLDocumentToString(&doc);
}
