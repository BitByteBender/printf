#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * stHandler - Handles percent specifiers
 * @curType: current position in the format string
 * @argC: pointer
 * @args: var arg list
 * @ptr: pointer to struct data
 * handles different cases for (%) sign instead
 * will get called in _printf.c
 */
void stHandler(const char **curType, int *argC, va_list args, struct data *ptr)
{
	(*curType)++;
	if (**curType == '\0')
	{
	write(1, "Err!\n", sizeof("Err!\n"));
	*argC = -1;
	return;
	}
	if (**curType == ptr->PercentSpecifier)
	{
	*argC += write(1, "%", sizeof(char));
	(*curType)++;
	}
	else if (**curType == ptr->Backslash)
	{
		(*curType)++;
		if (**curType == 'n')
			*argC += write(1, "\n", sizeof(char));
		else
		{
			*argC += write(1, "%", sizeof(char));
			(*curType)--;
		}
	}
	else
	{
		percentSignHandler(curType, argC, args);
	}
}
