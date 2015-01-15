#include <stdlib.h>
#include "mylib.h"

u16* videoBuffer = (u16*) 0x6000000;
void setPixel(int x, int y, u16 color)
{
    videoBuffer[y * 240 + x] = color;
}

void waitForVblank()
{
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER <= 160);
}

/*void drawRect(int r, int c, int width, int height, u16 color)
{
	int i;int j;
    for(i=r;i<r+height;i++){
	 for(j=c;j<c+width;j++){
	 	setPixel(j,i,color);
	 }
    }
}*/
void drawRect(int row, int col, int ht, int wid, unsigned short color)
{
	
	int r;
	for(r=0; r<ht; r++)
	{
		
		DMA[3].src = &color;
		DMA[3].dst = &videoBuffer[OFFSET(row+r, col, 240)];
		DMA[3].cnt = DMA_ON | DMA_SOURCE_FIXED | wid;
	
	}
}

int rectCollides(Rect a,Rect b)
{
	float ctax=(a.x+a.x+a.w)/2.0f;
	float ctay=(a.y+a.y+a.h)/2.0f;
	float ctbx=(b.x+b.x+b.w)/2.0f;
	float ctby=(b.y+b.y+b.h)/2.0f;
	float compx=abs(ctax-ctbx);
	float compy=abs(ctay-ctby);
	if((compx<=(a.w+b.w)/2.0f)&(compy<=(a.h+b.h)/2.0f)){
		return 1;
	}
	return 0;
}
void drawImage3(int x, int y, int width, int height, const u16* image)
{
	int i;int j;
    for(i=x;i<x+width;i++){
	 if(i<=240) for(j=y;j<y+height;j++){
	 	if(j<=160) setPixel(i,j,image[(j-y)*width+(i-x)]);
	 }
    }
}
