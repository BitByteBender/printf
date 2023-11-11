#include "../headers/main.h"
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
	_printf("\nMy name in chars:[%c, %c, %c, %c, %c, %c, %c, %c]", 'S', 'O', 'U', 'F', 'I', 'A', 'N', 'E');
	_printf("\nTeam name:{%s%s %c %s%s}\n\n", "Sad", "gali", '&', "Mena", "Ujiri");
	_printf("\nTeam name:{%s%s%c%s%s %c %s%s%c%s%s}\n\n", "Souf", "iane", ' ', "Sad", "gali", '&', "Ekoro", "mena", ' ', "Uj", "iri");
	
	return (0);
}
