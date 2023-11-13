#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * writeInts - prints integer
 * @val: integer to be printed
 * dynamically allocates memory to the buffer
 * frees memory at the end
 */
void writeInts(int val)
{
	int valHolder = val;
	unsigned short Length = CHECK_LENGTH(valHolder);
	char *buffer, *ptrBuffer;

	while (valHolder != 0)
	{
	valHolder /= 10;
	Length++;
	}

	buffer = (char *)malloc(Length + 2);

	if (buffer == NULL)
	{
	write(1, "Error!", 6);
	return;
	}

	valHolder = val;

	ptrBuffer = buffer + Length + 1;
	*ptrBuffer = '\0';

	while (valHolder != 0)
	{
	ptrBuffer--;
	*ptrBuffer = '0' + ABS(valHolder % 10);
	valHolder /= 10;
	}

	if (val < 0)
	{
	ptrBuffer--;
	*ptrBuffer = '-';
	}

	write(1, buffer, Length + 1);

	free(buffer);
}
