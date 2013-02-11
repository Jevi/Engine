#include "myEngine.h"

int main(int argc, char *argv[]) {

    myEngine::CreateInstance("workspace/demo", 640, 480, 0.0f, 9.81f);
    myEngine* en = myEngine::GetInstance();
	en->Start();
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}
