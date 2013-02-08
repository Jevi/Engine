#include "engine.h"

int main(int argc, char *argv[]) {
	std::unique_ptr<Engine> en(new Engine("workspace/demo", 640, 480, 9.81f));
	en->Start();
	system("pause");
	return 0;
}