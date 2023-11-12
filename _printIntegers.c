#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#define ABS(x) (((x) < 0) ? -(x) : (x))

int printIntegers(int value, int size)
{
	char Sign = '-', cDigit;
	unsigned short absValue = ABS(value), valueHolder = absValue;
	unsigned short Length = 0;
	int digit = 0;

	if (value == 0)
	{
	return (write(1, &value, size));
	}

	if (value < 0)
	{
	write(1, &Sign, size);
	absValue = -value;
	}

	do
	{
	valueHolder /= 10;
	Length++;
	} while (valueHolder != 0);

	if (absValue == 0)
	{
	return (write(1, "0", size));
	}

	do{
	 	digit = absValue / calcExponent(10, Length - 1);
		cDigit = '0' + digit;
		write(1, &cDigit, size);
		absValue %= (short)calcExponent(10, Length - 1);
		Length--;
	} while (Length > 0);

	return (1);
}
