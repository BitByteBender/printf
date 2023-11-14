#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * _printf - outputs data to console
 * @format: specified the type of args to be printed
 * processes the format string and prints specified data to console
 * Supports chars(%c), strings(%s) and percentSpecifier (%) using enums
 * checks if current char is part of format specifier or not
 * handles the case where (%) is at the end of a string
 * support (%%) as a special case and output it as a single (%)
 * Return:
 * total number of processed chars
 */
int _printf(const char *format, ...)
{
	struct data DataHandler = {'\\', '%'};
	int argCount = 0;
	const char *curType = format;
	struct data *ptrData = &DataHandler;

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*curType != '\0')
	{
		if (*curType != (ptrData->PercentSpecifier))
		{
		nonPercentHandler(&curType, &argCount);
		}
		else
		{
		stHandler(&curType, &argCount, args, ptrData);
		}
	}
	va_end(args);
	return (argCount);
}
