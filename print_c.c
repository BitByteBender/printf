#include "main.h"

/**
 * prints_char - prints a char
 * @val: argument
 * Return: (1)
 */

int printf_char(va_list val)
{
	char str;

	str = va_arg(val, int);
	putchar(str);
	return (1);
}
