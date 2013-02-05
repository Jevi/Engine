#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <sstream>
#include <Box2D/Box2D.h>

#include "component.h"

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
	std::vector<Component*> components;
	/**
	 Holds Entity's position, rotation and scale
	 */
	b2BodyDef bodyDef;
	Scale scale;

	Entity(std::string Id, float PosX, float PosY, float Rot, float ScaleX, float ScaleY) :
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
	std::string GetId()
	{
		return id;
	}
	/*
	 Returns component with unique name identifier
	 */
	Component* GetComponent(std::string Name);
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
	bool RemoveComponent(std::string Name);
	/*
	 Removes component from Entity component vector if it has a unique name identifier
	 */
	bool RemoveComponentAt(unsigned int Index);

	std::string ToString();

	// Additional Lua Accessors

	float GetX() { return bodyDef.position.x; }

	float GetY() { return bodyDef.position.y; }

	float GetAngle() { return bodyDef.angle; }

	float GetScaleX() { return scale.x; }

	float GetScaleY() {	return scale.y;	}

	void SetX(float x) { bodyDef.position.x = x; }

	void SetY(float y) { bodyDef.position.y = y; }

	void SetScaleX(float scalex) { scale.x = scalex; }

	void SetScaleY(float scaley) { scale.y = scaley; }

private:

	/*
	 Unique name identifier of Entity
	 */
	std::string id;
};

#endif
