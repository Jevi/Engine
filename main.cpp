#include "engine.h"
#include <Box2D/Box2D.h>

int main(int argc, char *argv[])
{
	Engine* en = Engine::GetInstance();
	en->Start();
	return 0;
}