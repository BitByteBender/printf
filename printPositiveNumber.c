#include "main.h"
#include <stdlib.h>

int digitCount(int);
/**
 * printPositiveNumber - prints a positive number
 * @Num: positive int to get printed
 * Return: number of char printed
 */
int printPositiveNumber(int Num)
{
	int currentDigit = 0, remainder = Num;
	int powNum = _pow(10, digitCount(remainder) - 1);
	unsigned short Counter = 1;

	while (powNum > 0)
	{
		currentDigit = remainder / powNum;
		_writeDigit(currentDigit);
		remainder = remainder % powNum;
		powNum = powNum / 10;
		Counter++;
	}

	return (Counter);
}
/**
 * digitCount - counts number of digit in an integer
 * @digit: integer to count digits
 * Return: number of ints digits
 */
int digitCount(int digit)
{
	short i = 0;

	while (digit != 0)
	{
	digit /= 10;
	i++;
	}

	return (i);
}
