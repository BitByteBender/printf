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
	struct stDataHandlers DataHandler = {'\\', '%'};
	int argCount = 0, dataTypeResult = 0;
	const char *curType = format;
	struct stDataHandlers *ptrData = &DataHandler;

	va_list args;

	enDataTypes Types;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*curType != '\0')
	{
	if (*curType == (ptrData->PercentSpecifier))
	{
		curType++;
		if (*curType == '\0')
			break;
		if (*curType == (ptrData->PercentSpecifier))
			argCount += write(1, curType, sizeof(char));
		else
		{
		Types = *curType;
		dataTypeResult = dataTypesHandler(Types, args);

		if (dataTypeResult == -1)
			return (-1);
		argCount += dataTypeResult;
		}
	}
	else
		argCount += write(1, curType, sizeof(char));
	curType++;
	}
	va_end(args);
	return (argCount);
}
