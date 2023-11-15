#include "main.h"

/**
 * _pow - perform power calculation
 * @base: base number to be powered
 * @expo: exponent value
 *
 * Return:
 * calculated exponent
 */
short _pow(short base, short expo)
{
	unsigned short i, exponent = 1;

	for (i = 0; i < expo; i++)
		exponent *= base;

	return (exponent);
}
