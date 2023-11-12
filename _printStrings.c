#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 *
 */
void writeStr(const char *str)
{
	unsigned short strLength = 0;

	while (str[strLength])
		strLength++;

	write(1, str, strLength);
}
