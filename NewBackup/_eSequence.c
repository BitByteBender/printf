#include "main.h"
#include <stdlib.h>
/**
 * escapeSequenceHandler - Handles escape sequences
 * @Seq: Escape sequence to be handled
 * function switches between several escape sequences
 * Return:
 * Number of chars processed
 * or 0 for unknown escape sequences
 */
int escapeSequenceHandler(char Seq)
{
	switch (Seq)
	{
	case (tab):
	writeFunc('\t', sizeof(char));
	return (1);
	case (newLine):
	writeFunc('\n', sizeof(char));
	return (1);
	}

	return (0);
}
