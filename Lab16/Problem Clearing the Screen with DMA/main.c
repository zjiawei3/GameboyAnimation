#include <stdlib.h>
#include "mylib.h"
#include "mystery.h"

extern const u16 mystery[38400];

int main(void)
{
		int i, j;
    REG_DISPCNT = MODE3 | BG2_ENABLE;

		/* Hey fix this Draw the image with DMA instead ;D */
		for (i = 0; i < 160; i++)
		{
			for (j = 0; j < 240; j++)
			{
				setPixel(j, i, mystery[240 * i + j]);
			}
		}
		
    while (1)
    {
        waitForVblank();
				/* Clear the screen here using DMA */
	for(i=0; i<160; i++)
	{
		
		DMA[3].src = RGB(0,0,0);
		DMA[3].dst = &videoBuffer[OFFSET(i, 0, 240)];
		DMA[3].cnt = DMA_ON | DMA_SOURCE_FIXED | 240;
	
	}
		
				/* Of course in a real mode3 game you don't have enough time to DMA clear the whole screen but just go with me here*/
    }
}
