#include "physics_component.h"
#include "graphics.h"
#include "debug.h"
#include "engine.h"
#include "engine_math.h"
#include "render_component.h"
#include "tinyxml2.h"

PhysicsComponent::PhysicsComponent(std::string Id, unsigned int BodyType, bool Enabled) :
		Component(Id, Component::PHYSICS), bodyType(BodyType), synched(false), density(1.0f), friction(1.0f), restitution(1.0f), allowSleep(true) {
	enabled = Enabled;
}

PhysicsComponent::~PhysicsComponent(void) {
	_world->DestroyBody(body);
}

void PhysicsComponent::Start() {

}

void PhysicsComponent::Update(unsigned long Dt) {
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
		std::shared_ptr<RenderComponent> renderComponent(std::static_pointer_cast < RenderComponent > (entity->GetComponent("render")));
		int width = renderComponent->GetSprite()->width;
		int height = renderComponent->GetSprite()->height;
		shape.SetAsBox(EngineMath::PixelsToMeters(((float) width) * entity->scale.x) / 2.0f, EngineMath::PixelsToMeters(((float) height) * entity->scale.y) / 2.0f);

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

std::string PhysicsComponent::ToString() {
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* componentElement = doc.NewElement("Component");
	componentElement->SetAttribute("id", id.c_str());
	componentElement->SetAttribute("type", Component::TypeToString(Component::PHYSICS).c_str());
	componentElement->SetAttribute("enabled", enabled);
	tinyxml2::XMLElement* physicsElement = doc.NewElement("Physics");
	physicsElement->SetAttribute("type", bodyType);
	physicsElement->SetAttribute("density", density);
	physicsElement->SetAttribute("friction", friction);
	physicsElement->SetAttribute("restitution", restitution);

	componentElement->LinkEndChild(physicsElement);
	doc.LinkEndChild(componentElement);
	return Debug::XMLDocumentToString(&doc);
}
