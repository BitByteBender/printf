#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
/**
 *
 */

void writeChar(char);

void writeStr(const char *);

typedef enum
{
	chars = 'c',
	strings = 's'
} enDataTypes;

struct stDataHandlers
{
	char Backslash;
	char PercentSpecifier;
};

int _printf(const char *format, ...)
{
	enDataTypes Types;
	struct stDataHandlers DataHandler = {'\\', '%'};
	unsigned short argCounter = 0;
	const char *strHolder, *currentType = format;
	struct stDataHandlers *ptrDataHandler = &DataHandler;
	
	va_list args;

	va_start(args, format);

	while (currentType[argCounter] != '\0')
	{
	Types = (enDataTypes)currentType[argCounter];

	if ((argCounter != 0 && currentType[argCounter - 1] == (ptrDataHandler->PercentSpecifier)) || currentType[0] == (ptrDataHandler->PercentSpecifier))
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
	
	argCounter++;	
	}

	va_end(args);
	
	return (argCounter);
}

void writeChar(char c)
{
	char *cBuffer = (char *)malloc(sizeof(char));

	if (cBuffer == NULL)
		exit(6);

	cBuffer[0] = c;

	write(STDOUT_FILENO, cBuffer, sizeof(char));

	free(cBuffer);
}

void writeStr(const char *str)
{
	unsigned short i = 0, strLength = 0;
	char *strBuffer;

	while (str[strLength])
		strLength++;

	strBuffer = (char *)malloc(strLength);

	if (strBuffer == NULL)
		exit(6);

	for (i = 0; i <= (strLength - 1); i++)
		strBuffer[i] = str[i];

	write(STDOUT_FILENO, strBuffer, strLength);

	free(strBuffer);
}
