#ifndef DEBUG_H
#define DEBUG_H

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include <iostream>
#include <string>
#include <sstream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

class Debug
{
public:

	static void Log(const char* format, ...);
	static string BoolToString(bool Bool);
	static string XMLDocumentToString(XMLDocument* doc);

	template<typename T>
	static string NumberToString(T Number)
	{
		ostringstream ss;
		ss << Number;
		return ss.str();
	}

private:

	static void ProcessElements(const XMLNode* ParentNode, ostringstream& os, unsigned int indents = 0);
	static const char* GetIndent(int indents);
};

#endif

