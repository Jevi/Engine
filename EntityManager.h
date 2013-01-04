#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>

#include "Entity.h"

class EntityManager
{
public:
	EntityManager(void);
	~EntityManager(void);

	void Add(Entity* object);
	void OnEvent();
	void OnRender();
	void RemoveAll();

private:

	std::vector<Entity*> entities;
};

#endif

