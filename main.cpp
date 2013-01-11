#include "engine.h"

int main(int argc, char *argv[])
{
	Engine* en = Engine::GetInstance();
	en->Start();
	return 0;
}