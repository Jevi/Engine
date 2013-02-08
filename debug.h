#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <sstream>

#include "tinyxml2.h"

class Debug {
public:

	enum LogLevel {
		LOG_DEBUG, LOG_PARM, LOG_ENTRY, LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_SEVERE
	};

	static void Log(LogLevel Level, const char* Format, ...);
	static std::string BoolToString(bool Bool);
	static std::string XMLDocumentToString(tinyxml2::XMLDocument* Doc);

	template<typename T>
	static std::string NumberToString(T Number) {
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}

private:

	static std::string LogLevelToString(LogLevel Level);
};

#endif

