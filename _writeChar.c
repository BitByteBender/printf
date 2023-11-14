#include "main.h"
#include <stdlib.h>
/**
 * intsHandler - handles integers data type
 * @integerHolder: integer holder
 * Return: size of int
 */
int writeChar(int charHolder)
{
	write(1, &charHolder, 1);
	return (sizeof(char));
}
