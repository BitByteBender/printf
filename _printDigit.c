#include "main.h"

/**
 * _printDigit - prints each positive integer digit
 * @value: positive integer to print
 */
void _printDigit(int value)
{
	char valHolder[BUFFER_SIZE];
	unsigned short i = 0;
	int j = 0;

	while (value > 0)
	{
	valHolder[i] = (value % 10) + '0';
	value /= 10;
	i++;
	}

	for (j = (i - 1); j >= 0; j--)
		_writeDigit(valHolder[j] - '0');
}
