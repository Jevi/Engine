#ifndef MY_COMPONENT_H
#define MY_COMPONENT_H

#include "myEntity.h"

class myEntity;

class myComponent {
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
	 Defines whether this component is enabled
	 */
	bool enabled;
    /*
     refers to this Components Entity owner
     */
    myEntity* entity;

    myComponent(std::string Id, unsigned int Type) :
			id(Id), type(Type), enabled(false), entity(NULL) {
	}

    virtual ~myComponent(void) {
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

protected:
    /*
     Unique name identifier for Component
     */
    std::string id;
    /*
     Component type
     */
    unsigned int type;
};

#endif
