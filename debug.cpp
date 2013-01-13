#include "debug.h"

void Debug::Log(const char* format, ...)
{
	va_list arguments;
	va_start(arguments, format);
	vprintf(format, arguments);
	va_end(arguments);
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