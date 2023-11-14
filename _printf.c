#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * _printf - outputs data to console
 * @format: specified the type of args to be printed
 * processes the format string and prints specified data to console
 * Supports chars(%c), strings(%s) using enums
 * Support PercentSpecifier (%) using struct
 *
 * checks if current char is part of format specifier or not
 *
 * Call for percentSignHandler to handle:
 * -> handles the case where (%) is at the end of a string
 * -> handles the cse where (%) is before a data type
 * -> support (%%) as a special case and output it as a single (%)
 * Return:
 * total counts of processed chars
 */
int _printf(const char *format, ...)
{
	struct stDataHandlers DataHandler = {'\\', '%'};
	int argCount = 0;
	const char *curType = format;
	struct stDataHandlers *ptrData = &DataHandler;

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*curType != '\0')
	{
	if (*curType != ptrData->PercentSpecifier)
	{
		argCount += write(1, curType, sizeof(char));
		curType++;
	}
	else
	{
		curType++;
		if (*curType == '\0')
		{
		write(1, "Err!\n", sizeof("Err!\n"));
		exit(-1);
		}
		if (*curType == ptrData->PercentSpecifier)
		{
		argCount += write(1, "%", sizeof(char));
		curType++;
		}
		else
			percentSignHandler(&curType, &argCount, args);
	}
	}
	va_end(args);
	return (argCount);
}
