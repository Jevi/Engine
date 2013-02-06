#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include <iostream>
#include <vector>

#include "entity.h"

class LevelManager {
protected:
    static unsigned int _currentLevel;
    static std::string _currentLevelPath;
    static std::vector<Entity*> _sharedEntities;
};

#endif
