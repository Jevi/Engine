#include "render_component.h"

RenderComponent::RenderComponent(string Name) :
		Component(Name)
{
	type = RENDER;
}

RenderComponent::RenderComponent(string Name, Texture2D* Sprite) :
		Component(Name)
{
	type = RENDER;
	sprite = Sprite;
}

RenderComponent::RenderComponent(string Name, Texture2D* Sprite, bool Enabled) :
		Component(Name)
{
	type = RENDER;
	sprite = Sprite;
	enabled = Enabled;
}

RenderComponent::~RenderComponent()
{
	sprite->OnUnload();
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
	Graphics::DrawTexture(sprite, entity->transform.position.x, entity->transform.position.y);
}

