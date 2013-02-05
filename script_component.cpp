#include "script_component.h"


ScriptComponent::ScriptComponent(std::string Id, std::string Filename, bool Enabled) :
		Component(Id, Component::SCRIPT), filename(Filename)
{
	enabled = Enabled;
}

ScriptComponent::~ScriptComponent(void)
{

}

void ScriptComponent::Start()
{

}

void ScriptComponent::Update(unsigned long dt)
{

}

std::string ScriptComponent::ToString()
{
	return "SCRIPT";
}