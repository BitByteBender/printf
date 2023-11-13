#include "main.h"
#include <stdlib.h>
/**
 * escapeSequenceHandler - Handles escape sequences
 * @Seq: Escape sequence to be handled
 * function switches between several escape sequences
 */
void escapeSequenceHandler(char Seq)
{
	struct stDataHandlers DataHandler = {'\\', '%'};

	if (Seq == DataHandler.PercentSpecifier)
	{
	writeFunc('%', sizeof(char));
	}
	else
	{
	switch (Seq)
	{
	case (tab):
	writeFunc('\t', sizeof(char));
	break;
	case (newLine):
	writeFunc('\n', sizeof(char));
	break;
	default:
	writeFunc('%', sizeof(char));
	writeFunc(Seq, sizeof(char));
	break;
	}
	}

}
