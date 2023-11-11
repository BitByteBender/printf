#include "../headers/main.h"
#include <stdio.h>

int main(void)
{
	unsigned short val = 4;
	const unsigned short Arr[] = {5, 9, 22};
	unsigned short *List = inputHandler(Arr, val);
	printf("%d, %d, %d\n", List[0], List[1], List[2]);
	return (0);
}
