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

	enum LogLevel
	{
		LOG_DEBUG, LOG_PARM, LOG_ENTRY, LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_SEVERE
	};

	static void Log(LogLevel level, const char* format, ...);
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
	static string LogLevelToString(LogLevel level)
	{
		switch (level)
		{
			case LOG_DEBUG:
				return "LOG_DEBUG";
				break;
			case LOG_PARM:
				return "LOG_PARAM";
				break;
			case LOG_ENTRY:
				return "LOG_ENTRY";
				break;
			case LOG_INFO:
				return "LOG_INFO";
				break;
			case LOG_WARNING:
				return "LOG_WARNING";
				break;
			case LOG_ERROR:
				return "LOG_ERROR";
				break;
			case LOG_SEVERE:
				return "LOG_SEVERE";
				break;
			default:
				return "LOG_DEFAULT";
				break;
		}
	}
};

#endif

