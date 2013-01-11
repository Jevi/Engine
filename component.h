#ifndef COMPONENT_H 
#define COMPONENT_H

#include "entity.h"
using namespace std;

class Entity;

class Component
{
public:
	//Constant fields representing component types
	static const int RENDER = 0;
	static const int AUDIO = 1;

	/*
	 Unique name identifier for Component
	 */
	string name;
	/*
	 Component type 
	 */
	int type;
	/*
	 Defines whether this component is enabled
	 */
	bool enabled;
	/*
	 refers to this Components Entity owner
	 */
	Entity* entity;

	Component(string Name) :
			name(Name), enabled(false), entity(NULL)
	{
	}

	virtual ~Component()
	{
		entity = NULL;
	}

	/*
	 Abstract Method. Must be implemented by child component class
	 */
	virtual void Start() = 0;
	/*
	 Abstract Method. Must be implemented by child component class
	 */
	virtual void Update(unsigned long dt) = 0;
};

#endif
