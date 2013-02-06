#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

class LevelManager {
protected:
    static unsigned int _currentLevel;
    static std::string _currentLevelPath;
    static std::vector<Entity*> _sharedEntities;
};

#endif // LEVEL_H
