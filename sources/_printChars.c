#include "../headers/main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 *
 */
void writeFunc(int value, int size)
{
	write(STDOUT_FILENO, &value, size);
}
