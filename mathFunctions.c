#include "../headers/main.h"

/**
 *
 */
short calcExponent(short base, short expo)
{
	unsigned short i, exponent = 1;

	for (i = 0; i < expo; i++)
		exponent *= base;

	return (exponent);
}
