#include <stdlib.h>
#include "mylib.h"
#include "mystery.h"

extern const u16 mystery[38400];
int i;
int j;
int main(void)
{
    REG_DISPCNT = MODE3 | BG2_ENABLE;
    while (1)
    {
        waitForVblank();
        /* Draw the mystery image (it is flipped horizontally and vertially)) stored in the array mystery defined in mystery.c onto the screen here*/
        /* Hint: start at the last pixel of the image and draw it in reverse */
	/*for(j=159;j>=0;j--){
		DMA[3].src = mystery;
		DMA[3].dst = &videoBuffer[OFFSET(j, 239, 240)];
		DMA[3].cnt = DMA_ON | DMA_SOURCE_INCREMENT |DMA_DESTINATION_DECREMENT| 240;
	}
	*/
		DMA[3].src = mystery;
		DMA[3].dst = &videoBuffer[38399];
		DMA[3].cnt = DMA_ON | DMA_DESTINATION_DECREMENT | 38400;	
	
							
							
				/* Now consider this what if the image was just flipped horizontally how could you draw it correctly with DMA? */
				
				/* Then consider if the image was just flipped vertically how could you draw it correctly with DMA? */
    }
}
