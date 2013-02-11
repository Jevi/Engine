#ifndef MY_LEVEL_MANAGER_H
#define MY_LEVEL_MANAGER_H

#include <iostream>
#include <vector>
#include <Box2D/Box2D.h>

#include "myEntity.h"

class myLevelManager {
protected:
	static unsigned int _currentLevel;
	static std::shared_ptr<b2World> _world;
	static std::vector<std::shared_ptr<myEntity> > _sharedEntities;
};

#endif
