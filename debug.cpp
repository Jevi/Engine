#include "debug.h"

void Debug::Log(LogLevel Level, const char* Format, ...)
{
	va_list args;
	va_start(args, Format);
	std::cout << "[" << LogLevelToString(Level) << "]\t";
	vprintf(Format, args);
	va_end(args);
	std::cout << std::endl;
}

std::string Debug::BoolToString(bool Bool)
{
	if (Bool)
	{
		return std::string("true");
	}
	return std::string("false");
}

std::string Debug::XMLDocumentToString(tinyxml2::XMLDocument* Doc)
{
	tinyxml2::XMLPrinter printer;
	Doc->Print(&printer);
	return printer.CStr();
}

std::string Debug::LogLevelToString(LogLevel Level)
{
	switch (Level)
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