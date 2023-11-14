#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 100

#define ABS(x) (((x) < 0) ? (-x) : (x))

#define CHECK_LENGTH(x) (((x) == 0) ? (0) : (1))
/**
 * typedef enum enDataTypes - holds data types
 * @enum: enumerates different data types
 */
typedef enum
{
chars = 'c',
strings = 's',
percentSpecifier = '%',
nullChar = 0
} enDataTypes;

/**
 * typedef enum enEscapeSequence - holds escape sequences
 * @enum: enumerates different escape sequences
 * @tab: for '\t'
 * @newLine: for '\n'
 */
typedef enum
{
tab = 't',
newLine = 'n'
} enEscapeSequences;

/**
 * struct data - structure public scoped by default
 * @Backslash: char that holds '\'
 * @PercentSpecifier: char that hold '%'
 */
struct data
{
char Backslash;
char PercentSpecifier;
};

short calcExponent(short, short);

void writeFunc(int, int);

void writeInts(int);

void writeStr(const char *);

int printIntegers(int, int);

int _printf(const char *, ...);

int dataTypesHandler(enDataTypes Types, va_list args);

int escapeSequenceHandler(char);

char fetchChars(va_list args);

void percentSignHandler(const char **, int *, va_list args);

int charsHandler(va_list args, int *);

int stringsHandler(va_list args, int *);

void stHandler(const char **, int *, va_list, struct data *ptr);

void nonPercentHandler(const char **curType, int *argC);
#endif /* MAIN_H */
