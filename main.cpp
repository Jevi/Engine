#include "engine.h"

int main(int argc, char *argv[]) {
	
	Engine::CreateInstance("workspace/demo", 640, 480, 0.0f, 9.81f);
	Engine* en = Engine::GetInstance();
	en->Start();
	system("pause");
	return 0;
}