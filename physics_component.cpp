#include "physics_component.h"

PhysicsComponent::PhysicsComponent(string Id, unsigned int BodyType, float Density, bool Enabled) :
		Component(Id, Component::PHYSICS), bodyType(BodyType), density(Density), synched(false)
{
	type = PHYSICS;
	enabled = Enabled;
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
			case 0:
				BodyDef.type = b2_staticBody;
				break;
			case 1:
				BodyDef.type = b2_dynamicBody;
			default:
				BodyDef.type = b2_dynamicBody;
				break;
		}
		body = world->CreateBody(&BodyDef);

		b2PolygonShape shape;
		int width = ((RenderComponent*) entity->GetComponent("render"))->GetSprite()->width;
		int height = ((RenderComponent*) entity->GetComponent("render"))->GetSprite()->height;
		shape.SetAsBox(EngineMath::PixelsToMeters((float) width) / 2.0f, EngineMath::PixelsToMeters((float) height) / 2.0f);

		b2FixtureDef FixtureDef;
		FixtureDef.shape = &shape;
		FixtureDef.density = density;
		FixtureDef.friction = 0.5f;
		body->CreateFixture(&FixtureDef);
		synched = true;
	}
	entity->transform = body->GetTransform();
}

string PhysicsComponent::ToString()
{
	return "";
}