#include "main.h"
#include <stdlib.h>
/**
 * writeChar - writes a single char to stdout
 * @charHolder: char to be printed
 * Return: size of char
 */
int writeChar(int charHolder)
{
	write(1, &charHolder, 1);
	return (sizeof(char));
}
