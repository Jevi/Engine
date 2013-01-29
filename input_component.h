#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "component.h"
#include "event_handler.h"

class InputComponent :
	public Component, public EventHandler
{
public:

	string id;
	bool enabled;

	InputComponent(string Id, bool Enabled);
	~InputComponent(void);

	void Start();

	void Update(unsigned long dt);

	string ToString();

};

#endif 