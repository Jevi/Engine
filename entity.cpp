#include "entity.h"
#include "render_component.h"
#include "physics_component.h"
#include "input_component.h"
#include "engine_math.h"
#include "debug.h"
#include "tinyxml2.h"
using namespace tinyxml2;

void Entity::Start() {
	//Iterate over the component list, initializing each component if it is enabled
	for (unsigned int i = 0; i < components.size(); ++i) {
		if (components[i]->enabled) {
			components[i]->Start();
		}
	}
}

void Entity::Update(unsigned long dt) {
	//Iterate over the component list, updating each component if it is enabled
	for (unsigned int i = 0; i < components.size(); ++i) {
		if (components[i]->enabled) {
			components[i]->Update(dt);
		}
	}
}

std::shared_ptr<Component> Entity::GetComponent(std::string Name) {
	for (unsigned int i = 0; i < components.size(); i++) {
		if (components[i]->id == Name) {
			return components[i];
		}
	}
	return NULL;
}

std::shared_ptr<Component> Entity::GetComponentAt(unsigned int Index) {
	//If the target index exceeds the number of objects in the list, then the component does not exist
	if (Index > components.size() - 1) {
		return NULL;
	}
	return components[Index];
}

bool Entity::AddComponent(std::shared_ptr<Component> NewComponent) {
	//make sure the component doesn't already exist
	for (unsigned int i = 0; i < components.size(); ++i) {
		if ((components[i] == NewComponent) || (components[i]->id == NewComponent->id)) {
			return false;
		}
	}

	//Add the component to the list
	components.push_back(NewComponent);
	NewComponent->entity = this;
	return true;
}

bool Entity::RemoveComponent(std::string Name) {
	//Iterate over the component list
	for (unsigned int i = 0; i < components.size(); ++i) {
		//If the current component's name matches the target name, then remove the component from the list
		if (components[i]->id == Name) {
			components.erase(components.begin() + i);
			return true;
		}
	}
	return false;
}

bool Entity::RemoveComponentAt(unsigned int Index) {
	//If the target index exceeds the number of objects in the component list, then the target index does not exist
	if (Index > (components.size() - 1)) {
		return false;
	}

	//Remove the component from the list
	components.erase(components.begin() + Index);
	return true;
}

Entity::~Entity(void) {

}

std::string Entity::ToString() {
	XMLDocument doc;
	XMLElement* root = doc.NewElement("Entity");
	root->SetAttribute("id", id.c_str());
	root->SetAttribute("x", EngineMath::MetersToPixels(bodyDef.position.x));
	root->SetAttribute("y", EngineMath::MetersToPixels(bodyDef.position.y));
	root->SetAttribute("rot", EngineMath::RadiansToDegrees(bodyDef.angle));
	root->SetAttribute("scalex", scale.x);
	root->SetAttribute("scaley", scale.y);
	doc.LinkEndChild(root);

	for (unsigned int i = 0; i < components.size(); ++i) {
		std::shared_ptr<Component> component = components[i];
		XMLElement* componentElement = doc.NewElement("Component");
		componentElement->SetAttribute("id", component->id.c_str());
		componentElement->SetAttribute("type", Component::TypeToString(component->type).c_str());
		componentElement->SetAttribute("enabled", component->enabled);

		switch (components[i]->type) {
			case Component::RENDER: {
				std::shared_ptr<RenderComponent> renderComponent = std::static_pointer_cast < RenderComponent > (components[i]);
				XMLElement* renderElement = doc.NewElement("Render");
				renderElement->SetAttribute("asset", renderComponent->GetSprite()->id.c_str());
				componentElement->LinkEndChild(renderElement);
			}
				break;
			case Component::PHYSICS: {
				std::shared_ptr<PhysicsComponent> physicsComponent = std::static_pointer_cast < PhysicsComponent > (components[i]);
				XMLElement* physicsElement = doc.NewElement("Physics");
				physicsElement->SetAttribute("type", physicsComponent->bodyType);
				physicsElement->SetAttribute("density", physicsComponent->density);
				physicsElement->SetAttribute("friction", physicsComponent->friction);
				physicsElement->SetAttribute("restitution", physicsComponent->restitution);
				physicsElement->SetAttribute("gravityScale", physicsComponent->gravityScale);
				componentElement->LinkEndChild(physicsElement);
			}
				break;
		}
		root->LinkEndChild(componentElement);
	}
	return Debug::XMLDocumentToString(&doc);
}
