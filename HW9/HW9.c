#include <stdio.h>
#include <stdlib.h>

#include "myLib.h"
#include "text.h"
#include "Lose.h"


u16 bgcolor=BLACK;
int seed=0;
int cscore=0;
int score=0;
Rect balls[15];
Rect player;
Rect playerold;
char str[41];
int dels[] = {-2, -1, 1, 2};
int status=0;
int i=0;
int j=0;


int isvalid(Rect a)
{
	if(a.x<0)return 0;
	if(a.y<0)return 0;
	if(a.x+a.w>160)return 0;
	if(a.y+a.h>240)return 0;
	return 1;
}
void draw(void)
{
	for(i=0;i<15;i++){
		drawRect(balls[i].x,balls[i].y,balls[i].w,balls[i].h,balls[i].color);
	}
	drawRect(player.x,player.y,player.w,player.h,player.color);
	sprintf(str,"Score: %d",score);
	drawString(0, 0, str, RED);
}
void initialize(void)
{
    REG_DISPCTL = MODE3 | BG2_ENABLE;
	score=0;
	cscore=0;
	for(i=0;i<15;i++){
		balls[i].x = rand()%80;
		balls[i].y = rand()%60;
		balls[i].xdel = dels[rand()%4];
		balls[i].ydel = dels[rand()%4];
		balls[i].w=3;balls[i].h=3;
		balls[i].color = rand()%32767;
	}
	player.x=100;
	player.y=100;
	player.xdel=0;
	player.ydel=0;
	player.w=5;
	player.h=5;
	player.color=WHITE;
	playerold=player;
	DMA[3].src = &bgcolor;
	DMA[3].dst = videoBuffer;
	DMA[3].cnt = DMA_ON | DMA_SOURCE_FIXED | 38400;
    	drawString(40, 40, "The True Man Stands The Last", RED);
	drawString(100, 60, "Press any key to start", RED);
	while(!KEY_DOWN_NOW(BUTTON_ANY))
	{
		seed++;
	}
    	drawString(40, 40, "The True Man Stands The Last", BLACK);
	drawString(100, 60, "Press any key to start", BLACK);
	draw();
	srand(seed);
}

void clear(void)
{
	for(i=0; i<15; i++)
		{
			drawRect(balls[i].x, balls[i].y, balls[i].w, balls[i].h, BLACK);
		}
	drawRect(player.x,player.y,player.w,player.h,BLACK);
	drawString(0, 0, str, RED);
}

void update(void)
{
	for(i=0;i<15;i++)
	{
		balls[i].x+=balls[i].xdel;
		balls[i].y+=balls[i].ydel;
		if(balls[i].x<0)balls[i].xdel=dels[rand()%2+2];
		if(balls[i].y<0)balls[i].ydel=dels[rand()%2+2];
		if(balls[i].x+balls[i].w>160)balls[i].xdel=dels[rand()%2];
		if(balls[i].y+balls[i].h>240)balls[i].ydel=dels[rand()%2];
		balls[i].color=RGB(rand()%31,rand()%31,rand()%31);
	}
	playerold=player;
	if(KEY_DOWN_NOW(BUTTON_LEFT))
		{
			player.xdel=-1;
		}else
	{if(KEY_DOWN_NOW(BUTTON_RIGHT))
		{
			player.xdel=1;
		}else{player.xdel=0;}}
	if(KEY_DOWN_NOW(BUTTON_UP))
		{
			player.ydel=-1;
		}else
	{if(KEY_DOWN_NOW(BUTTON_DOWN))
		{
			player.ydel=1;
		}else{player.ydel=0;}}

	player.y+=player.xdel;
	player.x+=player.ydel;
	if(!isvalid(player)){player.x=playerold.x;player.y=playerold.y;}
	cscore++;
	if(cscore==10){score++;cscore=0;}
}


void fail(void)
{
	DMA[3].src = Lose;
	DMA[3].dst = videoBuffer;
	DMA[3].cnt = DMA_ON | 38400;
	sprintf(str,"%d",score);
	drawString(120,100,str,RED);
	drawString(140,0,"Press A To Play Again/Press B To Exit",RED);
	while(KEY_DOWN_NOW(BUTTON_ANY))
	{
		seed++;
	}

	while(!KEY_DOWN_NOW(BUTTON_A))
	{
		seed++;
		if(KEY_DOWN_NOW(BUTTON_B)){status=1;break;}
	}	
	
	DMA[3].src = &bgcolor;
	DMA[3].dst = videoBuffer;
	DMA[3].cnt = DMA_ON | DMA_SOURCE_FIXED | 38400;
	draw();
	srand(seed);
	if(status==0)initialize();
    /*drawImage3(0, 0, 240, 160, (const u16 *)Lose);*/
}
void check(void)
{
	for(i=0;i<15;i++){
		if(rectCollides(balls[i],player)==1)fail();
	}
}

int main(void)
	{
		/* Set up REG_DISPCNT */
		initialize();
		while(status==0)
		{
			waitForVblank();
			clear();
			update();
			draw();
			check();
		}

		return 0;
	}
