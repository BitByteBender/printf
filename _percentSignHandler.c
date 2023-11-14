#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * percentSignHandler - Handles percent sign repetition
 * @curType: current position in format string
 * @argCount: pointer to counter of processed chars
 * @args: var arg list
 * -> handles the case where (%) is at the end of a string
 * -> support (%%) as a special case and output it as a single (%)
 * -> support and handles multiple (%)
 */
void percentSignHandler(const char **curType, int *argCount, va_list args)
{
	enDataTypes Types;
	int dataTypeResult = 0;

	while (**curType == '%')
	{
		*argCount += write(1, "%", sizeof(char));
		(*curType)++;
	}
	Types = **curType;
	switch (Types)
	{
	case (chars):
		dataTypeResult = dataTypesHandler(chars, args);
		break;
	case (strings):
		dataTypeResult = dataTypesHandler(strings, args);
		break;
	case (nullChar):
		write(1, "Err!\n", sizeof("Err!\n"));
		exit(-1);
	default:
		dataTypeResult = -1;
		break;
	}

	if (dataTypeResult == -1)
	{
		write(1, "Err!\n", sizeof("Err!\n"));
		exit(-1);
	}
	(*curType)++;
}
