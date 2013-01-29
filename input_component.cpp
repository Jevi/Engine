#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include "input_component.h"
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
	if (keystate[SDLK_RIGHT])
	{
		Debug::Log(Debug::LOG_DEBUG, "RIGHT");
       entity->bodyDef.position.x += EngineMath::PixelsToMeters(10);
	}
}

string InputComponent::ToString()
{
	return "INPUT COMPONENT";
}
