#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * dataHandler - handles formatted data printing
 * @curType: format string
 * @ptr: pointer to struct
 * @args: var arg list
 * processes the format string and prints specified data to console
 * Supports chars(%c), strings(%s) and percentSpecifier (%) using enums
 * checks if current char is part of format specifier or not
 * handles the case where (%) is at the end of a string
 * support (%%) as a special case and output it as a single (%)
 * Return:
 * total number of processed chars
 */
int dataHandler(const char *curType, struct data *ptr, va_list args)
{
	int argCount = 0;
	enDataTypes Types;

	while (*curType != '\0')
	{
	if (*curType == (ptr->PercentSpecifier))
	{
		curType++;
		if (*curType == '\0')
			break;
		if (*curType == (ptr->PercentSpecifier))
			argCount += write(1, &(ptr->PercentSpecifier), sizeof(char));
		else
		{
		Types = (enDataTypes)*curType;
		switch (Types)
		{
		case (chars):
			argCount += writeChar(va_arg(args, int));
			break;
		case (strings):
			argCount += writeStr(va_arg(args, char *));
			break;
		case (signedIntD):
		case (signedIntI):
			argCount += writeInts(va_arg(args, int));
			break;
		default:
			write(1, &(ptr->PercentSpecifier), sizeof(char));
			write(1, curType, sizeof(char));
			argCount += sizeof(char) * 2;
		}
	}
	}
	else
		argCount += write(1, curType, sizeof(char));
	curType++;
	}
	return (argCount);
}
