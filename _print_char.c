#include "../headers/main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 *
 */

void writeChar(char);

void writeStr(const char *);

char *_strcpy(char *, char *);

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
		writeChar(va_arg(args, int));
		break;
		case (strings):
		strHolder = va_arg(args, char *);
		writeStr(strHolder);
		break;
		}
	}
	else if (currentType[argCounter] == (ptrDataHandler->Backslash) && (argCounter == 0 || currentType[argCounter - 1] == (ptrDataHandler->PercentSpecifier)))
	{
		Esequences = (enEscapeSequences)currentType[argCounter + 1];
			switch (Esequences)
			{
			case (tab):
			writeChar('\t');
			break;
			case (newLine):
			writeChar('\n');
			break;
			}
	argCounter++;
	}
	else
	{
	writeChar(currentType[argCounter]);
	}
	argCounter++;	
	}

	va_end(args);
	
	return (argCounter);
}

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
