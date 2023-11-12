#include "../headers/main.h"
#include <unistd.h>
#include <stdlib.h>

int printIntegers(int value, int size)
{
	char Sign = '-', cDigit;
	unsigned short valueHolder = value;
	unsigned short Length = 0;
	int digit = 0;

	if (value == 0)
	{
	writeFunc('0', size);
	exit(6);
	}

	if (value < 0)
	{
	writeFunc(Sign, size);
	}

	while (valueHolder != 0)
	{
	valueHolder /= 10;
	Length++;
	}

	while (Length > 0)
	{
		digit = value / calcExponent(10, --Length);
		cDigit = '0' + digit;
		writeFunc(cDigit, size);
		value %= (short)calcExponent(10, Length);
	}

	return (value);
}
