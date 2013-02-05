#ifndef SCRIPTCOMPONENT_H
#define SCRIPTCOMPONENT_H

#include "component.h"

class ScriptComponent: public Component {
public:

	std::string filename;

	ScriptComponent(std::string Id, std::string Filename, bool Enabled);

	~ScriptComponent(void);

	void Start();

	void Update(unsigned long dt);

	std::string ToString();

private:

};

#endif
