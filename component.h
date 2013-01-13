#ifndef COMPONENT_H 
#define COMPONENT_H

#include "entity.h"
using namespace std;

class Entity;

class Component
{
public:

	//Constant fields representing component types
	static const unsigned int RENDER = 0;
	static const unsigned int AUDIO = 1;

	static string TypeToString(unsigned int Type)
	{
		switch (Type)
		{
		case RENDER:
			return string("RENDER");
			break;
		case AUDIO:
			return string("AUDIO");
			break;
		}
	}
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
