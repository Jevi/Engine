#ifndef SCRIPTCOMPONENT_H
#define SCRIPTCOMPONENT_H

#include "component.h"

class ScriptComponent: public Component
{
public:

	string filename;

	ScriptComponent(string Id, string Filename, bool Enabled);

	~ScriptComponent(void);

	void Start();

	void Update(unsigned long dt);

	string ToString();

private:

};

#endif
