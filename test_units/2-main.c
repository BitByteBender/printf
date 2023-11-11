#include "../headers/main.h"
#include <stdio.h>
/**
 *
 */
int main(void)
{
	const char *strHolder = "Hello world!";
	char Alphabets = 'A';

	_printf("%c", 'T');
	_printf("%s", "This is a test");

	_printf("%c", Alphabets);
	_printf("%s", strHolder);
	return (0);
}
