#ifndef DEBUG_H
#define DEBUG_H

#include <SDL.h>
#include <iostream>
#include <string>

using namespace std;

class Debug
{
public:

	static void Log(const char* format, ...);

};

#endif

