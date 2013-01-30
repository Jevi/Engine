#ifndef COMPONENT_H 
#define COMPONENT_H

#include "entity.h"
using namespace std;

class Entity;

class Component
{
public:

	enum ComponentType
	{
		RENDER, AUDIO, PHYSICS, INPUT
	};

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
			case PHYSICS:
				return string("PHYSICS");
				break;
			case INPUT:
				return string("INPUT");
				break;
			default:
				return string("DEFUALT");
				break;
		}
	}
	/*
	 Unique name identifier for Component
	 */
	string id;
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

	Component(string Id, unsigned int Type) :
			id(Id), type(Type), enabled(false), entity(NULL)
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

	virtual string ToString() = 0;
};

#endif
