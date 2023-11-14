#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * stringsHandler - handles strings data type
 * @args: variable arg list
 * @argCount: pointer to counted processed chars
 * this function performs a processing of a string dataType
 * Return: overall number of processed chars
 */
int stringsHandler(va_list args, int *argCount)
{
	enDataTypes Types = strings;
	int dataTypeResult = dataTypesHandler(Types, args);

	if (dataTypeResult == -1)
		return (-1);

	*argCount += dataTypeResult;
	return (*argCount);
}
