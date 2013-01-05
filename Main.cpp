#include "Engine.h"

int main(int argc, char *argv[])
{
	Engine* en = Engine::GetInstance();
	en->OnStart();
	return 0;
}