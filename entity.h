#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include "transform.h"
#include "component.h"
#include "debug.h"
using namespace std;

class Component;

class Entity
{
public:
	/**
	 Holds Entity's position, rotation and scale
	 */
	Transform transform;

	Entity(string Name, float PosX, float PosY, float Rot, float Scale) :
			name(Name), transform(PosX, PosY, Rot, Scale)
	{
	}

	virtual ~Entity()
	{
	}

	/*
	 Initializes Entity by initializing all enabled components
	 */
	void Start();
	/*
	 Updates all enabled components
	 */
	void Update(unsigned long dt);

	// Accessor Methods

	/*
	 Return Entity unique name identifier
	 */
	string GetName()
	{
		return name;
	}
	/*
	 Returns component with unique name identifier
	 */
	Component* GetComponent(string Name);
	/*
	 Returns component at specific index from Entity component vector
	 */
	Component* GetComponentAt(unsigned int Index);

	// Modifier Methods

	/*
	 Adds component to Entity component vector if it has a unique name identifier
	 */
	bool AddComponent(Component* NewComponent);
	/*
	 Removes component with unique name identifier
	 */
	bool RemoveComponent(string Name);
	/*
	 Removes component from Entity component vector if it has a unique name identifier
	 */
	bool RemoveComponentAt(unsigned int Index);

private:
	/*
	 Component vector of Entity which defines Entity properties
	 */
	vector<Component*> components;
	/*
	 Unique name identifier of Entity
	 */
	string name;
};

#endif
