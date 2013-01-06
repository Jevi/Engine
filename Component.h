#ifndef COMPONENT_H 
#define COMPONENT_H

#include "entity.h"
using namespace std;

class Entity;

class Component
{
public:
	//Constant fields representing component types
	static const int RENDER = 1;
	static const int AUDIO = 2;

	string name;				//The name of the component
	bool enabled;					//Is the component currently enabled?
	Entity* entity;			//The game object that owns this component
	int type;						//The type of component

	//Initializing Ctor
	Component(string Name) :
			name(Name), enabled(true), entity(NULL)
	{
	}

	//Dtor
	virtual ~Component()
	{
		entity = NULL;
	}

	//Abstract function, called when the scene is started
	virtual void Start() = 0;
	//Abstract function, called when the scene is updated
	virtual void Update(unsigned long dt) = 0;
};

#endif
