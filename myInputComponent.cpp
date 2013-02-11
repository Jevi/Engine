#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include "myInputComponent.h"
#include "myPhysicsComponent.h"
#include "myDebug.h"
#include "myMath.h"

myInputComponent::myInputComponent(std::string Id, bool Enabled) :
		myComponent(Id, myComponent::INPUT) {
	enabled = Enabled;
}

myInputComponent::~myInputComponent(void) {
}

void myInputComponent::Start() {

}

void myInputComponent::Update(unsigned long Dt) {
	Uint8* keystate = SDL_GetKeyState(NULL);
	if (entity->GetComponent("physics") != NULL) {
		std::shared_ptr<myPhysicsComponent> physicsComponent(std::static_pointer_cast < myPhysicsComponent > (entity->GetComponent("physics")));
		if (physicsComponent->body->IsAwake()) {
			if (keystate[SDLK_RIGHT]) {
				physicsComponent->body->SetTransform(b2Vec2(physicsComponent->body->GetTransform().p.x + myMath::PixelsToMeters(10), physicsComponent->body->GetTransform().p.y), physicsComponent->body->GetTransform().q.GetAngle());
			}

			if (keystate[SDLK_LEFT]) {
				physicsComponent->body->SetTransform(b2Vec2(physicsComponent->body->GetTransform().p.x - myMath::PixelsToMeters(10), physicsComponent->body->GetTransform().p.y), physicsComponent->body->GetTransform().q.GetAngle());
			}

			if (keystate[SDLK_UP]) {
				physicsComponent->body->SetTransform(b2Vec2(physicsComponent->body->GetTransform().p.x, physicsComponent->body->GetTransform().p.y - myMath::PixelsToMeters(10)), physicsComponent->body->GetTransform().q.GetAngle());
			}

			if (keystate[SDLK_DOWN]) {
				physicsComponent->body->SetTransform(b2Vec2(physicsComponent->body->GetTransform().p.x, physicsComponent->body->GetTransform().p.y + myMath::PixelsToMeters(10)), physicsComponent->body->GetTransform().q.GetAngle());
			}
		}
		else {
			physicsComponent->body->SetAwake(true);
		}
	}
}

std::string myInputComponent::ToString() {
	return "INPUT COMPONENT";
}
