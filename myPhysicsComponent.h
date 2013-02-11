#ifndef MY_PHYSICSCOMPONENT_H
#define MY_PHYSICSCOMPONENT_H

#include <Box2D/Box2D.h>
#include "myLevelManager.h"
#include "myComponent.h"

class myPhysicsComponent: public myComponent, public myLevelManager {
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

    myPhysicsComponent(std::string Id, unsigned int BodyType, bool Enabled);
    ~myPhysicsComponent(void);

	void Start();

	void Update(unsigned long Dt);

	std::string ToString();

};

#endif
