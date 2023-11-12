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
	enDataTypes Types;
	enEscapeSequences Esequences;
	struct stDataHandlers DataHandler = {'\\', '%'};
	unsigned short argCount = 0;
	const char *strHolder, *curType = format;
	struct stDataHandlers *ptrData = &DataHandler;

	va_list args;

	va_start(args, format);

	while (curType[argCount] != '\0')
	{
	Types = (enDataTypes)curType[argCount];

	if ((argCount != 0 && curType[argCount - 1] == (ptrData->PercentSpecifier))
	|| curType[argCount] == (ptrData->PercentSpecifier))
	{
		switch (Types)
		{
		case (chars):
		writeFunc(va_arg(args, int), sizeof(char));
		break;
		case (strings):
		strHolder = va_arg(args, char *);
		writeStr(strHolder);
		break;
		case (signedInteger):
		printIntegers(va_arg(args, int), sizeof(int));
		break;
		}
	}
	else if (curType[argCount] == (ptrData->Backslash) && (argCount == 0
	|| curType[argCount - 1] == (ptrData->PercentSpecifier)))
	{
		Esequences = (enEscapeSequences)curType[argCount + 1];
			switch (Esequences)
			{
			case (tab):
			writeFunc('\t', sizeof(char));
			break;
			case (newLine):
			writeFunc('\n', sizeof(char));
			break;
			}
	argCount++;
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
