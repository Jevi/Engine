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
	Transform transform;							// The object's transform
	//Initializing Ctor
	Entity(string Name, float PosX, float PosY, float Rot, float Scale) :
			name(Name), transform(PosX, PosY, Rot, Scale)
	{
	}

	virtual ~Entity()
	{
	}

	//Initializes the game object by initializing each of its attached components
	void Start();
	//Updates the game object by updating each of its attached components
	void Update(unsigned long dt);

	// Getters
	string GetName()
	{
		return name;
	}
	Component* GetComponent(string Name);
	Component* GetComponentAt(unsigned int Idx);

	// Modifiers
	bool AddComponent(Component* NewComponent);
	bool RemoveComponent(string Name);
	bool RemoveComponentAt(unsigned int Idx);

private:
	vector<Component*> components;
	string name;								// The unique name of the game object
};

#endif
