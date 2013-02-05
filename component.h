#ifndef COMPONENT_H 
#define COMPONENT_H

#include "entity.h"

class Entity;

class Component {
public:

	enum ComponentType {
		RENDER, AUDIO, PHYSICS, INPUT, SCRIPT
	};

	static std::string TypeToString(unsigned int Type) {
		switch (Type) {
			case RENDER:
				return std::string("RENDER");
				break;
			case AUDIO:
				return std::string("AUDIO");
				break;
			case PHYSICS:
				return std::string("PHYSICS");
				break;
			case INPUT:
				return std::string("INPUT");
				break;
			case SCRIPT:
				return std::string("SCRIPT");
				break;
			default:
				return std::string("DEFUALT");
				break;
		}
	}
	/*
	 Unique name identifier for Component
	 */
	std::string id;
	/*
	 Component type
	 */
	unsigned int type;
	/*
	 Defines whether this component is enabled
	 */
	bool enabled;
	/*
	 refers to this Components Entity owner
	 */
	Entity* entity;

	Component(std::string Id, unsigned int Type) :
			id(Id), type(Type), enabled(false), entity(NULL) {
	}

	virtual ~Component(void) {
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

	virtual std::string ToString() = 0;

	std::string GetId() {
		return id;
	}

	unsigned int GetType() {
		return type;
	}

	bool IsEnabled() {
		return enabled;
	}
};

#endif
