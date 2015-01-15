/* FIXME
   The videoBuffer is located at address 0x6000000
   The videoBuffer contains 38400 shorts.
   where the first one is at location 0x6000000
   the next one is at location 0x6000002
   Define a VARIABLE named videoBuffer that can be used
   to access all 38400 pixels.
 */
#include "timedlablib.h"
u16* videoBuffer = (u16*) 0x6000000;

void setPixel(int r, int c, u16 color)
{
	videoBuffer[OFFSET3(r, c)] = color;/* FIXME IMPLEMENT THIS */
}

void waitForVBlank()
{
	/* FREEBIE :D */
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 160);
}

/* Clears the screen
 * Please clear the screen in any color
 * of your choosing other than black.
 * You must use your RGB Macro declared in mylib.h
 */
void clearScreen(u16 color)
{
	/* FIXME Implement this */
	int r;int c;
	for(r=0;r<160;r++){
		for(c=0;c<240;c++)setPixel(r, c, color);
	}
}

/* Draws the cursor which is just the portion of the 
 * image the cursor is currently located
 */
void drawCursor(Cursor cursor)
{
 /* FIXME Implement this */
 /* Note you will need to reference the mystery array in this function */
	int r=cursor.row;
	int c=cursor.col;
	int h=cursor.h;
	int w=cursor.w;
	for(r=cursor.row;r<cursor.row+h;r++){
		for(c=cursor.col;c<cursor.col+w;c++)setPixel(r, c, cursor.pic[OFFSET3(r, c)]);
	}
}

/* Draws the AWESOME TITLE SCREEN using set pixel */
void drawTitle(const u16* title)
{
	/* FIXME Implement this */
	int r;int c;
	for(r=0;r<160;r++){
		for(c=0;c<240;c++)setPixel(r, c, title[OFFSET3(r, c)]);
	}
}
