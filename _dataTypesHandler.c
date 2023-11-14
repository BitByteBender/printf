#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
/**
 * dataTypesHandler - Handles multiple data types
 * @Types: type of data to be handled
 * @args: variable arg-list
 * this function perform a switch based on
 * chosen data type
 * Return:
 * number of processed chars
 */
int dataTypesHandler(enDataTypes Types, va_list args)
{
	char charHolder, *strHolder;

	switch (Types)
	{
	case (chars):
	charHolder = (char)va_arg(args, int);
	return (write(1, &charHolder, sizeof(char)));
	case (strings):
	strHolder = va_arg(args, char *);
	if (strHolder == NULL)
		return (write(1, "(nil)", sizeof("(nil)")));

	return (write(1, strHolder, strlen(strHolder)));
	case (percentSpecifier):
		return (write(1, "%", sizeof(char)));
	default:
		return (-1);
	}
}
