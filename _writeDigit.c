#include "main.h"

/**
 * _writeDigit - writes a single digit to stdout
 * @value: digit to be written
 */
void _writeDigit(int value)
{
	char charDigit = value + '0';

	write(1, &charDigit, sizeof(char));
}
