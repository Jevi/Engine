#ifndef MY_ENTITY_H
#define MY_ENTITY_H

#include <vector>
#include <iostream>
#include <Box2D/Box2D.h>

#include "myComponent.h"

class myComponent;

class myEntity {
public:

	struct Scale {
		float x, y;
		Scale(float X, float Y) {
			x = X;
			y = Y;
		}
	};

	/*
	 Component vector of Entity which defines Entity properties
	 */
	std::vector<std::shared_ptr<myComponent> > components;

    /*
	 Holds Entity's position, rotation and scale
	 */
	b2BodyDef bodyDef;
	Scale scale;

    myEntity(std::string Id, float PosX, float PosY, float Rot, float ScaleX, float ScaleY);

    virtual ~myEntity();

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
    std::string GetId() {
        return id;
    }

	/*
	 Returns component with unique name identifier
	 */
	std::shared_ptr<myComponent> GetComponent(std::string Name);
	/*
	 Returns component at specific index from Entity component vector
	 */
    std::shared_ptr<myComponent> GetComponent(unsigned int Index);

	// Modifier Methods

	/*
	 Adds component to Entity component vector if it has a unique name identifier
	 */
	bool AddComponent(std::shared_ptr<myComponent> NewComponent);
	/*
	 Removes component with unique name identifier
	 */
	bool RemoveComponent(std::string Name);
	/*
	 Removes component from Entity component vector if it has a unique name identifier
	 */
	bool RemoveComponentAt(unsigned int Index);

	std::string ToString();

    // Lua Specific Acessors

//   myComponent* LuaGetComponent(std::string Name);

//   myComponent* LuaGetComponentAt(unsigned int Index);

private:

	/*
	 Unique name identifier of Entity
	 */
	std::string id;
};

#endif
