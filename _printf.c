#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * _printf - outputs data to console
 * @format: specified the type of args to be printed
 * processes the format string and prints specified data to console
 * Supports chars(%c), strings(%s) and signed-ints(%d) using enums
 * Support escape sequences such as \t (tab) and \n (new line) using enums
 * suppot backslash & percent specifier
 * checks if current char is part of format specifier or not
 * checks for escape sequences after a backslash
 * Return:
 * total number of processed chars
 */
int _printf(const char *format, ...)
{
	struct stDataHandlers DataHandler = {'\\', '%'};
	unsigned short argCount = 0;
	const char *curType = format;
	struct stDataHandlers *ptrData = &DataHandler;

	va_list args;

	if (format == NULL)
	{
	return (-1);
	}

	va_start(args, format);

	while (curType[argCount] != '\0')
	{
	if (curType[argCount] == (ptrData->PercentSpecifier))
	{
		argCount++;
		if (curType[argCount] == '\\')
		{
		argCount += escapeSequenceHandler(curType[argCount + 1]);
		argCount++;
		}
		else
		{
		dataTypesHandler(curType[argCount], args);
		}
	}
	else
	{
	writeFunc(curType[argCount], sizeof(char));
	}
	argCount++;
	}
	va_end(args);
	return (argCount);
}
