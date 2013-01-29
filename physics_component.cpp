#include "physics_component.h"
#include "graphics.h"
#include "debug.h"
#include "engine.h"
#include "engine_math.h"
#include "render_component.h"
#include "tinyxml2.h"

PhysicsComponent::PhysicsComponent(string Id, unsigned int BodyType, bool Enabled) :
		Component(Id, Component::PHYSICS), bodyType(BodyType), synched(false)
{
	enabled = Enabled;

	density = 1.0f;
	friction = 1.0f;
	restitution = 1.0f;
}

PhysicsComponent::~PhysicsComponent(void)
{
	b2World* world = Engine::GetWorld();
	world->DestroyBody(body);
}

void PhysicsComponent::Start()
{

}

void PhysicsComponent::Update(unsigned long dt)
{
	if (!synched)
	{
		b2World* world = Engine::GetWorld();
		b2BodyDef BodyDef;
		BodyDef.position.Set(entity->transform.p.x, entity->transform.p.y);
		BodyDef.angle = entity->transform.q.GetAngle();

		switch (bodyType)
		{
			case StaticBody:
				BodyDef.type = b2_staticBody;
				break;
			case DynamicBody:
				BodyDef.type = b2_dynamicBody;
			default:
				BodyDef.type = b2_dynamicBody;
				break;
		}
		body = world->CreateBody(&BodyDef);

		b2PolygonShape shape;
		RenderComponent* renderComponent = ((RenderComponent*) entity->GetComponent("render"));
		int width = renderComponent->GetSprite()->width;
		int height = renderComponent->GetSprite()->height;
		shape.SetAsBox(EngineMath::PixelsToMeters(((float) width) * entity->scale) / 2.0f, EngineMath::PixelsToMeters(((float) height) * entity->scale) / 2.0f);

		b2FixtureDef FixtureDef;
		FixtureDef.shape = &shape;
		FixtureDef.density = density;
		FixtureDef.friction = friction;
		FixtureDef.restitution = restitution;
		body->CreateFixture(&FixtureDef);
		synched = true;
	}
	entity->transform = body->GetTransform();
}

string PhysicsComponent::ToString()
{
	XMLDocument doc;
	XMLElement* componentElement = doc.NewElement("Component");
	componentElement->SetAttribute("id", id.c_str());
	componentElement->SetAttribute("type", Component::TypeToString(Component::PHYSICS).c_str());
	componentElement->SetAttribute("enabled", enabled);
	XMLElement* physicsElement = doc.NewElement("Physics");
	physicsElement->SetAttribute("type", bodyType);
	physicsElement->SetAttribute("density", density);
	physicsElement->SetAttribute("friction", friction);
	physicsElement->SetAttribute("restitution", restitution);

	componentElement->LinkEndChild(physicsElement);
	doc.LinkEndChild(componentElement);
	return Debug::XMLDocumentToString(&doc);
}
