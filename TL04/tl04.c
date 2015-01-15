#include <stdio.h>
#include <stdlib.h>

#include "timedlablib.h"
#include "title.h"
#include "mystery.h"
int main(void)
{
	/* Define a variable of type Cursor here
	and initialize it to whatever you want
	(as long as it makes sense!) */
	int seed;
	u16 bgcolor;
	Cursor cursor;
	cursor.row=75;
	cursor.col=115;
	cursor.w=10;
	cursor.h=10;
	cursor.pic=mystery;
	/* Set up REG_DISPCNT using 
	The SETMODE MACRO you defined in timedlablib.h
	The SYMBOLS BG2_ENABLE and MODE3 are already defined for you
	*/
	SETMODE(BG2_ENABLE,MODE3);
	waitForVBlank();
	drawTitle(title);
	seed=0;
	while(!(KEY_DOWN_NOW(BUTTONS))){
		seed++;
	}
	srand(seed);
	bgcolor=RGB(rand()%31,rand()%31,rand()%31);
	while(1)
	{
		/* Wait for Vertical Blank */
		waitForVBlank();
		clearScreen(bgcolor);
	if(KEY_DOWN_NOW(BUTTON_LEFT))
		{
			cursor.col--;
		}else
	{if(KEY_DOWN_NOW(BUTTON_RIGHT))
		{
			cursor.col++;
		}}
	if(KEY_DOWN_NOW(BUTTON_UP))
		{
			cursor.row--;
		}else
	{if(KEY_DOWN_NOW(BUTTON_DOWN))
		{
			cursor.row++;
		}}
	if(KEY_DOWN_NOW(BUTTON_A))
		{
			cursor.w--;cursor.h--;
		}else
	{if(KEY_DOWN_NOW(BUTTON_B))
		{
			cursor.w++;cursor.h++;
		}}
		drawCursor(cursor);
	}
	
	return 0;
}
