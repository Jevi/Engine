#include "Debug.h"

void Debug::Log(const char* format, ...)
{
	va_list arguments;
	va_start(arguments, format);
	cout << SDL_GetTicks() << "\t";
	vprintf(format, arguments);
	va_end(arguments);
	cout << endl;
}