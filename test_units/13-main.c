#include "../main.h"
/**
 *
 */
int main(void)
{	
	_printf("%c\n", 'x');
	_printf("\n");
	_printf("%s", "This is a string using new _printf");
	_printf("\n");
	_printf("t");
	_printf("\n");
	_printf("testing the newly created _printf");
	_printf("\n\n");
	_printf("%c", 'y');
	_printf("\n%c\n", 'z');
	_printf("*********************");
	_printf("\nCharacter:[%c]\n", 'P');
	_printf("Character:[%c]", 'L');
	_printf("\nCharacter:[%c]", 'O');
	_printf("\nCharacter:[%c]\n", 'T');
	_printf("\nMy name in chars:[%c, %c, %c, %c, %c, %c, %c, %c]", 'T', 'R', 'A', 'F', 'A', 'L', 'G', 'A');
	_printf("\nTeam name:{%s%s %c %s%s}\n\n", "Naha", "rami", '&', "Olga", "Kenmo");
	_printf("\nTeam name:{%s%s%c%s%s %c %s%s%c%s%s}\n\n", "Naha", "rami", ' ', "Onami", "dono", '&', "Olga", "kenmo", ' ', "Uj", "iri");	
	_printf("Integer test:[%d]", (1 + 1));
	_printf("%%");
	_printf("%");
	return (0);
}
