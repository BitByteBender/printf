#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * writeInts - prints integer
 * @val: integer to be printed
 * checks if val is 0 or negative
 * extract digits from val and store them in buffer
 * adds negative sign if val was negative
 * writes buffer in reverse
 */
void writeInts(int val)
{
	char buffer[BUFFER_SIZE];
	size_t valChecker = 0, Length = 0;
	unsigned short i = 0;

	if (val == 0)
	{
	write(1, "0", 1);
	return;
	}

	if (val < 0)
	{
	valChecker = 1;
	val = -val;
	}

	while (val > 0 && Length < BUFFER_SIZE)
	{
	buffer[Length++] = '0' + (val % 10);
	val /= 10;
	}

	if (Length >= sizeof(buffer))
	{
	write(1, "Error!", 6);
	return;
	}

	if (valChecker)
	{
	buffer[Length++] = '-';
	}

	for (i = 0; i < Length; i++)
		write(1, &buffer[Length - i - 1], 1);
}
