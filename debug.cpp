#include "debug.h"

void Debug::Log(LogLevel level, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	cout << "[" << LogLevelToString(level) << "]\t";
	vprintf(format, args);
	va_end(args);
	cout << endl;
}

string Debug::BoolToString(bool Bool)
{
	if (Bool)
	{
		return string("true");
	}
	return string("false");
}

string Debug::XMLDocumentToString(XMLDocument* doc)
{
	XMLPrinter printer;
	doc->Print(&printer);
	return printer.CStr();
}
