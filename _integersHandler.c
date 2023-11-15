#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * integersHandler - prints integer
 * @args: variable arg list
 * checks if val is 0 or negative
 * checks if Number is less than 0
 * Return: number of chars to be printed
 */

int integersHandler(va_list args)
{
	int Number = va_arg(args, int);
	unsigned short i = 0;

	if (Number < 0)
	{
	writeChar('-');
	Number = -Number;
	i++;
	}

	i += printPositiveNumber(Number);
	return (i);
}
