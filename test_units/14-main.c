#include "../main.h"
#include <stdio.h>
/**
 *
 */
int main(void)
{	
	printf("%c\n", 'x');
	printf("\n");
	printf("%s", "This is a string using new _printf");
	printf("\n");
	printf("t");
	printf("\n");
	printf("testing the newly created _printf");
	printf("\n\n");
	printf("%c", 'y');
	printf("\n%c\n", 'z');
	printf("*********************");
	printf("\nCharacter:[%c]\n", 'P');
	printf("Character:[%c]", 'L');
	printf("\nCharacter:[%c]", 'O');
	printf("\nCharacter:[%c]\n", 'T');
	printf("\nMy name in chars:[%c, %c, %c, %c, %c, %c, %c, %c]", 'S', 'O', 'U', 'F', 'I', 'A', 'N', 'E');
	printf("\nTeam name:{%s%s %c %s%s}\n\n", "Sad", "gali", '&', "Mena", "Ujiri");
	printf("\nTeam name:{%s%s%c%s%s %c %s%s%c%s%s}\n\n", "Souf", "iane", ' ', "Sad", "gali", '&', "Ekoro", "mena", ' ', "Uj", "iri");	
	printf("%");
	return (0);
}
