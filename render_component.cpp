#include "render_component.h"

RenderComponent::RenderComponent(string Name) :
		Component(Name)
{
	type = RENDER;
}

RenderComponent::RenderComponent(string Name, Sprite* Sprite) :
		Component(Name)
{
	type = RENDER;
	sprite = Sprite;
}

RenderComponent::RenderComponent(string Name, Sprite* Sprite, bool Enabled) :
		Component(Name)
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

