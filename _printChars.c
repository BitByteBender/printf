#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * writeFunc - prints a character
 * @value: value to be printed
 * @size: size to be allocated
 */
void writeFunc(int value, int size)
{
	write(1, &value, size);
}
