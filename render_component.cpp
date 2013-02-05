#include "render_component.h"
#include "physics_component.h"
#include "engine_math.h"
#include "graphics.h"
#include "tinyxml2.h"
#include "debug.h"

RenderComponent::RenderComponent(std::string Id) :
		Component(Id, Component::RENDER)
{
}

RenderComponent::RenderComponent(std::string Id, Sprite* Sprite) :
		Component(Id, Component::RENDER)
{
	sprite = Sprite;
}

RenderComponent::RenderComponent(std::string Id, Sprite* Sprite, bool Enabled) :
		Component(Id, Component::RENDER)
{
	sprite = Sprite;
	enabled = Enabled;

	if (enabled)
	{
		sprite->Load();
	}
}

RenderComponent::~RenderComponent(void)
{
	sprite->Unload();
}

void RenderComponent::Start()
{

}

void RenderComponent::Update(unsigned long Dt)
{
	Render();
}

void RenderComponent::Render()
{
	if (entity->GetComponent("physics") != NULL)
	{
		PhysicsComponent* physicsComponent = ((PhysicsComponent*) entity->GetComponent("physics"));
		if (physicsComponent->body && physicsComponent->synched)
		{
			b2Vec2 bodyVerticies[4];
			b2Vec2 bodyCenter = physicsComponent->body->GetWorldCenter();
			float rotation = physicsComponent->body->GetAngle();
			for (unsigned int i = 0; i < 4; i++)
			{
				bodyVerticies[i] = ((b2PolygonShape*) (physicsComponent->body->GetFixtureList()->GetShape()))->GetVertex(i);
			}
			Graphics::DrawTexture(sprite, bodyVerticies, bodyCenter, rotation);
		}
	}
	else
	{
		float x = entity->bodyDef.position.x;
		float y = entity->bodyDef.position.y;
		float rotation = entity->bodyDef.angle;
		float scaleX = entity->scale.x;
		float scaleY = entity->scale.y;
		Graphics::DrawTexture(sprite, x, y, rotation, scaleX, scaleY);
	}
}

std::string RenderComponent::ToString()
{
	XMLDocument doc;
	XMLElement* componentElement = doc.NewElement("Component");
	componentElement->SetAttribute("id", id.c_str());
	componentElement->SetAttribute("type", Component::TypeToString(Component::RENDER).c_str());
	componentElement->SetAttribute("enabled", enabled);

	XMLElement* renderElement = doc.NewElement("Render");
	renderElement->SetAttribute("asset", sprite->id.c_str());

	componentElement->LinkEndChild(renderElement);
	doc.LinkEndChild(componentElement);
	return Debug::XMLDocumentToString(&doc);
}

