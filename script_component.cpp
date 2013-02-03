#include "script_component.h"
#include "engine.h"

ScriptComponent::ScriptComponent(string Id, string Filename, bool Enabled) :
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

string ScriptComponent::ToString()
{
	return "SCRIPT";
}