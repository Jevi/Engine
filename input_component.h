#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "component.h"

class InputComponent: public Component
{
public:

	InputComponent(std::string Id, bool Enabled);
	~InputComponent(void);

	void Start();

	void Update(unsigned long Dt);

	std::string ToString();

};

#endif 
