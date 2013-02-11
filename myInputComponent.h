#ifndef MY_INPUTCOMPONENT_H
#define MY_INPUTCOMPONENT_H

#include "myComponent.h"

class myInputComponent: public myComponent {
public:

    myInputComponent(std::string Id, bool Enabled);
    ~myInputComponent(void);

	void Start();

	void Update(unsigned long Dt);

	std::string ToString();

};

#endif 
