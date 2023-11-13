#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
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
	char charHolder;

	switch (Types)
	{
	case (chars):
	charHolder = (char)va_arg(args, int);
	return (write(1, &charHolder, sizeof(char)));
	case (strings):
	return (write(1, va_arg(args, char *), sizeof(char *)));
	case (percentSpecifier):
	return (write(1, "%", sizeof(char)));
	default:
	return (write(1, "Err! Data types", sizeof("Err! Data types")));
	}
}
