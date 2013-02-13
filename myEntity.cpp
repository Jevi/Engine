#include "myEntity.h"
#include "myRenderComponent.h"
#include "myPhysicsComponent.h"
#include "myInputComponent.h"
#include "myMath.h"
#include "myDebug.h"
#include "tinyxml2.h"

myEntity::myEntity(std::string Id, float PosX, float PosY, float Rot, float ScaleX, float ScaleY) :
        id(Id), scale(ScaleX, ScaleY) {
    bodyDef.position.x = PosX;
    bodyDef.position.y = PosY;
    bodyDef.angle = Rot;
}

myEntity::~myEntity(void) {

}

void myEntity::Start() {
	//Iterate over the component list, initializing each component if it is enabled
	for (auto component : components) {
		if (component->enabled) {
			component->Start();
		}
	}
}

void myEntity::Update(unsigned long dt) {
	//Iterate over the component list, updating each component if it is enabled
	for (auto component : components) {
		if (component->enabled) {
			component->Update(dt);
		}
	}
}

std::shared_ptr<myComponent> myEntity::GetComponent(std::string Name) {
    for (std::shared_ptr<myComponent> component : components) {
        if (component->GetId() == Name) {
			return component;
		}
	}
	return NULL;
}

std::shared_ptr<myComponent> myEntity::GetComponent(unsigned int Index) {
	//If the target index exceeds the number of objects in the list, then the component does not exist
	if (Index > components.size() - 1) {
		return NULL;
	}
	return components[Index];
}

bool myEntity::AddComponent(std::shared_ptr<myComponent> NewComponent) {
	//make sure the component doesn't already exist
    for (std::shared_ptr<myComponent> component : components) {
        if ((component == NewComponent) || (component->GetId() == NewComponent->GetId())) {
			return false;
		}
	}

	//Add the component to the list
	components.push_back(NewComponent);
	NewComponent->entity = this;
	return true;
}

bool myEntity::RemoveComponent(std::string Name) {
	//Iterate over the component list
	for (unsigned int i = 0; i < components.size(); ++i) {
		//If the current component's name matches the target name, then remove the component from the list
        if (strcmp(components[i]->GetId().c_str(), Name.c_str()) == 0) {
			components.erase(components.begin() + i);
			return true;
		}
	}
	return false;
}

bool myEntity::RemoveComponentAt(unsigned int Index) {
	//If the target index exceeds the number of objects in the component list, then the target index does not exist
	if (Index > (components.size() - 1)) {
		return false;
	}

	//Remove the component from the list
	components.erase(components.begin() + Index);
	return true;
}

std::string myEntity::ToString() {
	/*tinyxml2::XMLDocument doc;
	 tinyxml2::XMLElement* root = doc.NewElement("Entity");
	 root->SetAttribute("id", id.c_str());
	 root->SetAttribute("x", EngineMath::MetersToPixels(bodyDef.position.x));
	 root->SetAttribute("y", EngineMath::MetersToPixels(bodyDef.position.y));
	 root->SetAttribute("rot", EngineMath::RadiansToDegrees(bodyDef.angle));
	 root->SetAttribute("scalex", scale.x);
	 root->SetAttribute("scaley", scale.y);
	 doc.LinkEndChild(root);

	 for (unsigned int i = 0; i < components.size(); ++i) {
	 std::shared_ptr<Component> component = components[i];
	 tinyxml2::XMLElement* componentElement = doc.NewElement("Component");
	 componentElement->SetAttribute("id", component->id.c_str());
	 componentElement->SetAttribute("type", Component::TypeToString(component->type).c_str());
	 componentElement->SetAttribute("enabled", component->enabled);

	 switch (components[i]->type) {
	 case Component::RENDER: {
	 std::shared_ptr<RenderComponent> renderComponent = std::static_pointer_cast < RenderComponent > (components[i]);
	 tinyxml2::XMLElement* renderElement = doc.NewElement("Render");
	 renderElement->SetAttribute("asset", renderComponent->GetSprite()->id.c_str());
	 componentElement->LinkEndChild(renderElement);
	 }
	 break;
	 case Component::PHYSICS: {
	 std::shared_ptr<PhysicsComponent> physicsComponent = std::static_pointer_cast < PhysicsComponent > (components[i]);
	 tinyxml2::XMLElement* physicsElement = doc.NewElement("Physics");
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
	 return Debug::XMLDocumentToString(&doc);*/
	return "ENTITY";
}
