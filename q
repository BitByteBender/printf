#include "../headers/main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 *
 */

short calcExponent(short , short);

void writeFunc(int, int);

void writeStr(const char *);

void printIntegers(int, int);

typedef enum
{
	chars = 'c',
	strings = 's',
	signedInteger = 'd'
	/*octHex_signedInteger = 'i'*/
} enDataTypes;

typedef enum
{
	tab = 't',
	newLine = 'n'
} enEscapeSequences;

struct stDataHandlers
{
	char Backslash;
	char PercentSpecifier;
};

int _printf(const char *format, ...)
{
	enDataTypes Types;
	enEscapeSequences Esequences;

	struct stDataHandlers DataHandler = {'\\', '%'};
	unsigned short argCounter = 0;
	const char *strHolder, *currentType = format;
	struct stDataHandlers *ptrDataHandler = &DataHandler;
	
	va_list args;

	va_start(args, format);
	
	
	while (currentType[argCounter] != '\0')
	{
	Types = (enDataTypes)currentType[argCounter];
		
	if ((argCounter != 0 && currentType[argCounter - 1] == (ptrDataHandler->PercentSpecifier)) || currentType[argCounter] == (ptrDataHandler->PercentSpecifier))
	{
		switch (Types)
		{
		case (chars):
		writeFunc(va_arg(args, int), sizeof(char));
		break;
		case (strings):
		strHolder = va_arg(args, char *);
		writeStr(strHolder);
		break;
		case (signedInteger):
		printIntegers(va_arg(args, int), sizeof(int));
		break;
		}
	}
	else if (currentType[argCounter] == (ptrDataHandler->Backslash) && (argCounter == 0 || currentType[argCounter - 1] == (ptrDataHandler->PercentSpecifier)))
	{
		Esequences = (enEscapeSequences)currentType[argCounter + 1];
			switch (Esequences)
			{
			case (tab):
			writeFunc('\t', sizeof(char));
			break;
			case (newLine):
			writeFunc('\n', sizeof(char));
			break;
			}
	argCounter++;
	}
	else
	{
	writeFunc(currentType[argCounter], sizeof(char));
	}
	argCounter++;	
	}

	va_end(args);
	
	return (argCounter);
}

void printIntegers(int value, int size)
{
	char Sign = '-', cDigit;
	unsigned short valueHolder = value;
	unsigned short Length = 0;
	int digit = 0;

	if (value == 0)
	{
	write(STDIN_FILENO, &value, size);
	return;
	}

	if (value < 0)
	{
	write(STDIN_FILENO, &Sign, size);
	value = -value;
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
		write(STDOUT_FILENO, &cDigit, size);
		value %= (short)calcExponent(10, Length);
	}


}

void writeFunc(int value, int size)
{
	write(STDOUT_FILENO, &value, size);
}

void writeStr(const char *str)
{
	unsigned short strLength = 0;

	while (str[strLength])
		strLength++;

	write(STDOUT_FILENO, str, strLength);
}

short calcExponent(short base, short expo)
{
	unsigned short i, expo(base);

	for (i = 0; i < expo; i++)
		expo = expo * base;

	return (expo);
}
