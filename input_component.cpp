#include "input_component.h"
#include "debug.h"


InputComponent::InputComponent(string Id, bool Enabled)
	: Component(Id, Component::INPUT), id(Id)
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

	if (keystate[SDLK_DOWN])
	{
		Debug::Log(Debug::LOG_DEBUG, "keyDOWN");
	}
}

string InputComponent::ToString()
{
	return "INPUT COMPONENT";
}
