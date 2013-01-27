#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include <Box2D/Box2D.h>

#include "graphics.h"
#include "debug.h"
#include "engine.h"
#include "engine_math.h"
#include "component.h"

using namespace std;

class Engine;

class PhysicsComponent: public Component
{
public:

	b2Body* body;
	unsigned int bodyType;
	float density;

	PhysicsComponent(string Id, unsigned int BodyType, float Density, bool Enabled);
	~PhysicsComponent(void);

	void Start();

	void Update(unsigned long dt);

	string ToString();

private:
	bool synched;
};

#endif
