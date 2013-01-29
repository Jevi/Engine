#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include <Box2D/Box2D.h>
#include "component.h"

using namespace std;

class PhysicsComponent: public Component
{
public:

	static enum BodyType
	{
		StaticBody, DynamicBody
	};

	b2Body* body;
	unsigned int bodyType;
	float density;
	float friction;
	float restitution;
	bool synched;

	PhysicsComponent(string Id, unsigned int BodyType, bool Enabled);
	~PhysicsComponent(void);

	void Start();

	void Update(unsigned long dt);

	string ToString();

};

#endif
