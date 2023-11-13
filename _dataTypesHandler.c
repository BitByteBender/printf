#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 * dataTypesHandler - Handles multiple data types
 * @Types: type of data to be handled
 * @args: variable arg-list
 * this function perform a switch based on
 * chosen data type
 */
void dataTypesHandler(char Types, va_list args)
{
	switch (Types)
	{
	case (chars):
	writeFunc(va_arg(args, int), sizeof(char));
	break;
	case (strings):
	writeStr(va_arg(args, char *));
	break;
	case (signedInteger):
	writeInts(va_arg(args, int));
	break;
	default:
	writeFunc('%', sizeof(char));
	break;
	}
}
