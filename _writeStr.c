#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * writeStr - handles strings data type
 * @strHolder: string to be printed
 * checks if NULL replace with (nil)
 * Return:
 * total number of chars
 */
int writeStr(char *strHolder)
{
	int argCount = 0;

	if (strHolder == NULL)
	{
		write(1, "(nil)", sizeof("(nil)"));
		argCount += sizeof("(nil)");
	}
	else
	{
		write(1, strHolder, strlen(strHolder));
		argCount += strlen(strHolder);
	}

	return (argCount);
}
