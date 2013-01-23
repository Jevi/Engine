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
	float x = entity->transform.position.x;
	float y = entity->transform.position.y;
	float rotation = entity->transform.rotation;
	float scale = entity->transform.scale;

	Graphics::DrawTexture(sprite, x, y, rotation, scale);
	// Graphics::DrawQuad(x, y, sprite->width * scale, sprite->height * scale, 255, 0, 0, 255);
}

string RenderComponent::ToString()
{
	ostringstream os;
	os << "Name: " << id << " Type: " << Asset::TypeToString(type) << " Entity: " << entity->GetName() << " Enabled: " << Debug::BoolToString(enabled) << endl;
	// os << sprite->ToString();
	return os.str();
}

