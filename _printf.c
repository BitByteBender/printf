#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>

/**
 *
 */
<<<<<<< HEAD

void writeChar(char);

void writeStr(const char *);

typedef enum
{
	chars = 'c',
	strings = 's'
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

=======
>>>>>>> 8063231... Committing changes to master
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
<<<<<<< HEAD

void writeChar(char c)
{
	write(STDOUT_FILENO, &c, sizeof(char));
}

void writeStr(const char *str)
{
	unsigned short strLength = 0;

	while (str[strLength])
		strLength++;

	write(STDOUT_FILENO, str, strLength);
}
=======
>>>>>>> 8063231... Committing changes to master
