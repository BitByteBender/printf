#include "main.h"
#include <stdlib.h>
/**
 * escapeSequenceHandler - Handles escape sequences
 * @Seq: Escape sequence to be handled
 * function switches between several escape sequences
 */
void escapeSequenceHandler(char Seq)
{
	switch (Seq)
	{
	case (tab):
	writeFunc('\t', sizeof(char));
	break;
	case (newLine):
	writeFunc('\n', sizeof(char));
	break;
	}

}
