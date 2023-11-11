#include "../headers/main.h"
#include <stdio.h>
/**
 *
 */
int main(void)
{	
	_printf("%c", 'x');
	putchar('\n');
	_printf("%s", "something fishy with this _printf");
	putchar('\n');
	_printf("t");
	putchar('\n');
	/*_printf('g');*/
	_printf("testing newly created _printf");
	_printf("\n");
	putchar('\n');
	return (0);
}
