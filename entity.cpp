#include "entity.h"

void Entity::Start()
{
	//Iterate over the component list, initializing each component if it is enabled
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		if (components[i]->enabled)
		{
			components[i]->Start();
		}
	}
}

void Entity::Update(unsigned long dt)
{
	//Iterate over the component list, updating each component if it is enabled
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		if (components[i]->enabled)
		{
			components[i]->Update(dt);
		}
	}
}

Component* Entity::GetComponent(string Name)
{
	for (unsigned int i = 0; i < components.size(); i++)
	{
		if (components[i]->name == Name)
		{
			return components[i];
		}
	}
	return NULL;
}

Component* Entity::GetComponentAt(unsigned int Index)
{
	//If the target index exceeds the number of objects in the list, then the component does not exist
	if (Index > components.size() - 1)
	{
		return NULL;
	}
	return components[Index];
}

bool Entity::AddComponent(Component* NewComponent)
{
	Debug::Log("Trying to add: %s", NewComponent->name.c_str());
	//make sure the component doesn't already exist
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		if ((components[i] == NewComponent) || (components[i]->name == NewComponent->name))
		{
			return false;
		}
	}

	//Add the component to the list
	components.push_back(NewComponent);
	NewComponent->entity = this;
	return true;
}

bool Entity::RemoveComponent(string Name)
{
	//Iterate over the component list
	for (unsigned int i = 0; i < components.size(); ++i)
	{
		//If the current component's name matches the target name, then remove the component from the list
		if (components[i]->name == Name)
		{
			components.erase(components.begin() + i);
			return true;
		}
	}

	return false;
}

bool Entity::RemoveComponentAt(unsigned int Index)
{
	//If the target index exceeds the number of objects in the component list, then the target index does not exist
	if (Index > (components.size() - 1))
	{
		return false;
	}

	//Remove the component from the list
	components.erase(components.begin() + Index);
	return true;
}

