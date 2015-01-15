#include "io.h"
#include <stdio.h>

int scan_nextInt(void)
{
	/* "BLACK MAGIC" nah just look up scanf if you want to know what this does.*/
	
	int readInNumber = 0;
	while(!scanf("%d", &readInNumber))
	{
		printf("HEY SILLY BILLY I WANT A NUMBER\n");
	}
	return readInNumber;
}

char scan_next(void)
{
	char readInChar = 0;
	while(!scanf("%c", &readInChar))
	{
		printf("HEY SILLY BILLY I WANT A CHARACTER\n");
	}
	return readInChar;
}
