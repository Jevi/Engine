#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <sstream>
#include <Box2D/Box2D.h>

#include "component.h"
using namespace std;

class Component;

class Entity
{
public:

	struct Scale
	{
		float x, y;
		Scale(float X, float Y)
		{
			x = X;
			y = Y;
		}
	};

	/*
	 Component vector of Entity which defines Entity properties
	 */
	vector<Component*> components;
	/**
	 Holds Entity's position, rotation and scale
	 */
	b2BodyDef bodyDef;
	Scale scale;

	Entity(string Id, float PosX, float PosY, float Rot, float ScaleX, float ScaleY) :
			id(Id), scale(ScaleX, ScaleY)
	{
		bodyDef.position.x = PosX;
		bodyDef.position.y = PosY;
		bodyDef.angle = Rot;
	}

	virtual ~Entity();

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
	string GetId()
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
	 Unique name identifier of Entity
	 */
	string id;
};

#endif
