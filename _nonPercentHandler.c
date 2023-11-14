#include "main.h"
#include <stdlib.h>
/**
 * nonPercentHandler -handls non percent specifier
 * @curType: current position in the format string
 * @argC: pointer
 * function will get triggered
 * once *curType != ptrData->PercentSpecifier
 */
void nonPercentHandler(const char **curType, int *argC)
{
	*argC += write(1, *curType, sizeof(char));
	(*curType)++;
}
