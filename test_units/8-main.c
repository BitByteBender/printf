#include "../headers/main.h"
#include <stdio.h>
/**
 *
 */
int main(void)
{
	const char *strHolder = "Hello world!";
	char Alphabets = 'A';

	_printf("%c\n", 'K');
	_printf("%s\n", "We are testing!!!");

	_printf("c\n", Alphabets);
	_printf("s\n", strHolder);
	
	return (0);
}
