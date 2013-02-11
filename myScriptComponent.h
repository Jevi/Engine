#ifndef MY_SCRIPTCOMPONENT_H
#define MY_SCRIPTCOMPONENT_H

#include "myComponent.h"

class myScriptComponent: public myComponent {
public:

	std::string filename;

    myScriptComponent(std::string Id, std::string Filename, bool Enabled);

    ~myScriptComponent(void);

	void Start();

	void Update(unsigned long dt);

	std::string ToString();

private:

};

#endif
