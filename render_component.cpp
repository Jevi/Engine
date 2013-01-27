#include "render_component.h"

RenderComponent::RenderComponent(string Id) :
		Component(Id, Component::RENDER)
{
	type = RENDER;
}

RenderComponent::RenderComponent(string Id, Sprite* Sprite) :
		Component(Id, Component::RENDER)
{
	type = RENDER;
	sprite = Sprite;
}

RenderComponent::RenderComponent(string Id, Sprite* Sprite, bool Enabled) :
		Component(Id, Component::RENDER)
{
	type = RENDER;
	sprite = Sprite;
	enabled = Enabled;

	if (enabled)
	{
		sprite->Load();
	}
}

RenderComponent::~RenderComponent()
{
	sprite->Unload();
}

void RenderComponent::Start()
{

}

void RenderComponent::Update(unsigned long dt)
{
	Render();
}

void RenderComponent::Render()
{
	float x = entity->transform.p.x;
	float y = entity->transform.p.y;
	float rotation = entity->transform.q.GetAngle();
	float scale = entity->scale;
	Graphics::DrawTexture(sprite, x, y, rotation, scale);
}

string RenderComponent::ToString()
{
	XMLDocument doc;
	XMLElement* root = doc.NewElement("Component");
	root->SetAttribute("id", id.c_str());
	root->SetAttribute("type", Component::TypeToString(Component::RENDER).c_str());
	root->SetAttribute("enabled", enabled);
	doc.LinkEndChild(root);
	return Debug::XMLDocumentToString(&doc);
}

