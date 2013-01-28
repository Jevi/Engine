#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include <Box2D/Box2D.h>

#include "graphics.h"
#include "debug.h"
#include "engine.h"
#include "engine_math.h"
#include "component.h"
#include "tinyxml2.h"

using namespace std;

class Engine;

class PhysicsComponent: public Component
{
public:

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
