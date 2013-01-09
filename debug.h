#ifndef DEBUG_H
#define DEBUG_H

#ifdef _WIN32
	#include <SDL.h>
#else
	#include <SDL/SDL.h>
#endif

#include <iostream>
#include <string>

using namespace std;

class Debug
{
public:

	static void Log(const char* format, ...);
};

#endif

