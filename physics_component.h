#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include <Box2D/Box2D.h>
#include "level_manager.h"
#include "component.h"

class PhysicsComponent: public Component, public LevelManager {
public:

	enum BodyType {
		StaticBody, DynamicBody
	};

	b2Body* body;
	bool synched;
	unsigned int bodyType;
	float density;
	float friction;
	float restitution;
	float gravityScale;
	bool allowSleep;

	PhysicsComponent(std::string Id, unsigned int BodyType, bool Enabled);
	~PhysicsComponent(void);

	void Start();

	void Update(unsigned long Dt);

	std::string ToString();

};

#endif
