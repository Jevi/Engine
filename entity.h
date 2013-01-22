#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <sstream>

#include "transform.h"
#include "component.h"
#include "debug.h"
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

class Component;

class Entity
{
public:
	/**
	 Holds Entity's position, rotation and scale
	 */
	Transform transform;

	Entity(string Id, float PosX, float PosY, float Rot, float Scale) :
			id(Id), transform(PosX, PosY, Rot, Scale)
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
		return id;
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

	string ToString();

private:
	/*
	 Component vector of Entity which defines Entity properties
	 */
	vector<Component*> components;
	/*
	 Unique name identifier of Entity
	 */
	string id;
};

#endif
