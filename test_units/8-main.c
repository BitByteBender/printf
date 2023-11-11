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

	_printf("%c\n", Alphabets);
	_printf("%s\n", strHolder);
	
	printf("b");
	printf("test");
	/*printf("t", "trying this with standard printf%!!!!");
	printf("f", '%');*/
	
	_printf("s", "Not using %!!!!");
	_printf("c", '%');

	_printf("\n%s\n", "Testing new line");
	return (0);
}
