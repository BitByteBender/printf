#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 *
 */
void writeFunc(int value, int size)
{
	write(1, &value, size);
}
