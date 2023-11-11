#include "../headers/main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
/**
 *
 */

void writeChar(char);

void writeStr(const char *);

<<<<<<< HEAD
=======
char *_strcpy(char *, char *);

>>>>>>> origin/soufiane_workspace
typedef enum
{
	chars = 'c',
	strings = 's'
} enDataTypes;

<<<<<<< HEAD
=======
typedef enum
{
	tab = 't',
	newLine = 'n'
} enEscapeSequences;

>>>>>>> origin/soufiane_workspace
struct stDataHandlers
{
	char Backslash;
	char PercentSpecifier;
};

int _printf(const char *format, ...)
{
	enDataTypes Types;
<<<<<<< HEAD
=======
	enEscapeSequences Esequences;

>>>>>>> origin/soufiane_workspace
	struct stDataHandlers DataHandler = {'\\', '%'};
	unsigned short argCounter = 0;
	const char *strHolder, *currentType = format;
	struct stDataHandlers *ptrDataHandler = &DataHandler;
	
	va_list args;

	va_start(args, format);
<<<<<<< HEAD

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
	
=======
	
	
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
>>>>>>> origin/soufiane_workspace
	argCounter++;	
	}

	va_end(args);
	
	return (argCounter);
}

void writeChar(char c)
{
<<<<<<< HEAD
	char *cBuffer = (char *)malloc(sizeof(char));

	if (cBuffer == NULL)
		exit(6);

	cBuffer[0] = c;

	write(STDOUT_FILENO, cBuffer, sizeof(char));

	free(cBuffer);
=======
	write(STDOUT_FILENO, &c, sizeof(char));
>>>>>>> origin/soufiane_workspace
}

void writeStr(const char *str)
{
<<<<<<< HEAD
	unsigned short i = 0, strLength = 0;
	char *strBuffer;
=======
	unsigned short strLength = 0;
>>>>>>> origin/soufiane_workspace

	while (str[strLength])
		strLength++;

<<<<<<< HEAD
	strBuffer = (char *)malloc(strLength);

	if (strBuffer == NULL)
		exit(6);

	for (i = 0; i <= (strLength - 1); i++)
		strBuffer[i] = str[i];

	write(STDOUT_FILENO, strBuffer, strLength);

	free(strBuffer);
=======
	write(STDOUT_FILENO, str, strLength);
}

char *_strcpy(char *Dest, char *src)
{
	unsigned short i = 0, srcLength = 0;
	
	while (src[srcLength])
		srcLength++;

	if (src == NULL)
		return (NULL);
	
	for (i = 0; i <= (srcLength - 1); i++)
	{
	Dest[i] = src[i];
	}
	Dest[srcLength] = '\0';
	return (Dest);
>>>>>>> origin/soufiane_workspace
}
