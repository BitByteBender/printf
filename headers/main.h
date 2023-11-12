#ifndef MAIN_H
#define MAIN_H

/**
 *
 */
typedef enum
{
chars = 'c',
strings = 's',
signedInteger = 'd'
/*octHex_signedInteger = 'i'*/
} enDataTypes;

/**
 *
 */
typedef enum
{
tab = 't',
newLine = 'n'
} enEscapeSequences;

/**
 *
 */
struct stDataHandlers
{
char Backslash;
char PercentSpecifier;
};

short calcExponent(short, short);

void writeFunc(int, int);

void writeStr(const char *);

int printIntegers(int, int);

int _printf(const char *, ...);
#endif /* MAIN_H */
