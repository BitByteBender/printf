#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * charsHandler - handles chars data type
 * @args: variable argument list
 * @argCount: pointer to counted processed chars
 * this function processe the (char) data type
 * Return: overall number of processed chars
 */
int charsHandler(va_list args, int *argCount)
{
	enDataTypes Types = chars;
	int dataTypeResult = dataTypesHandler(Types, args);

	if (dataTypeResult == -1)
		return (-1);

	*argCount += dataTypeResult;
	return (*argCount);
}
