#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include <iostream>
#include <vector>
#include <Box2D/Box2D.h>

#include "entity.h"

class LevelManager {
protected:
	static unsigned int _currentLevel;
	static std::shared_ptr<b2World> _world;
	static std::vector<std::shared_ptr<Entity> > _sharedEntities;
};

#endif
