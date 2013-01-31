#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include "input_component.h"
#include "physics_component.h"
#include "debug.h"
#include "engine_math.h"

InputComponent::InputComponent(string Id, bool Enabled) :
		Component(Id, Component::INPUT)
{
	enabled = Enabled;
}

InputComponent::~InputComponent(void)
{
}

void InputComponent::Start()
{

}

void InputComponent::Update(unsigned long dt)
{
	Uint8* keystate = SDL_GetKeyState(NULL);
	if (entity->GetComponent("physics") != NULL)
	{
		PhysicsComponent* physicsComponent = (PhysicsComponent*) entity->GetComponent("physics");
		if (physicsComponent->body->IsAwake())
		{
			if (keystate[SDLK_RIGHT])
			{
				physicsComponent->body->SetTransform(b2Vec2(physicsComponent->body->GetTransform().p.x + EngineMath::PixelsToMeters(10), physicsComponent->body->GetTransform().p.y), physicsComponent->body->GetTransform().q.GetAngle());
			}

			if (keystate[SDLK_LEFT])
			{
				physicsComponent->body->SetTransform(b2Vec2(physicsComponent->body->GetTransform().p.x - EngineMath::PixelsToMeters(10), physicsComponent->body->GetTransform().p.y), physicsComponent->body->GetTransform().q.GetAngle());
			}

			if (keystate[SDLK_UP])
			{
				physicsComponent->body->SetTransform(b2Vec2(physicsComponent->body->GetTransform().p.x, physicsComponent->body->GetTransform().p.y - EngineMath::PixelsToMeters(10)), physicsComponent->body->GetTransform().q.GetAngle());
			}

			if (keystate[SDLK_DOWN])
			{
				physicsComponent->body->SetTransform(b2Vec2(physicsComponent->body->GetTransform().p.x, physicsComponent->body->GetTransform().p.y + EngineMath::PixelsToMeters(10)), physicsComponent->body->GetTransform().q.GetAngle());
			}
		}
		else
		{
			physicsComponent->body->SetAwake(true);
		}
	}
}

string InputComponent::ToString()
{
	return "INPUT COMPONENT";
}
