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
	if (entity->GetComponent("physics") != NULL)
	{
		if (((PhysicsComponent*) entity->GetComponent("physics"))->body && ((PhysicsComponent*) entity->GetComponent("physics"))->synched)
		{
			b2Vec2 bodyVerticies[4];
			b2Vec2 bodyCenter = ((PhysicsComponent*) entity->GetComponent("physics"))->body->GetWorldCenter();
			float rotation = ((PhysicsComponent*) entity->GetComponent("physics"))->body->GetAngle();
			for (unsigned int i = 0; i < 4; i++)
			{
				bodyVerticies[i] = ((b2PolygonShape*) (((PhysicsComponent*) entity->GetComponent("physics"))->body->GetFixtureList()->GetShape()))->GetVertex(i);
			}
			Graphics::DrawTexture(sprite, bodyVerticies, bodyCenter, rotation);
		}
	}
	else
	{
		float x = entity->transform.p.x;
		float y = entity->transform.p.y;
		float rotation = entity->transform.q.GetAngle();
		float scale = entity->scale;
		Graphics::DrawTexture(sprite, x, y, rotation, scale);
	}
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

