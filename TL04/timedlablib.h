#ifndef MY_LIB_H
#define MY_LIB_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned int vu32;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef volatile signed char vs8;
typedef volatile signed short vs16;
typedef volatile signed int vs32;


/* FIXME 1) Define and typedef a structure called Cursor here */
/* A Cursor should know its position (row col or x y) and size (width height) */
typedef struct
{
	int row;
	int col;
	int w;
	int h;
	const u16* pic;
} Cursor;

/* FIXME 2) The display control register is a device register located at memory address 0x4000000
	The display control register is a pointer to an unsigned short please define a SYMBOL
	named REG_DISPCNT that can be used to ACCESS this location*/
#define REG_DISPCNT (*(u16*) 0x4000000)

/* FIXME 3) The scanline counter register is a device register located at memory address 0x4000006
  The scan line counter register is a device register which holds an unsigned short.  Please define
  a SUMBOL named SCANLINECOUNTER that can be used to ACCESS this location.  NOTE this device registers
  value can change UNEXPECTEDLY */
#define SCANLINECOUNTER (*(vu16 *)0x4000006)

/* FIXME 4) The buttons register is a device register located at memory address 0x4000130
  The buttons register is a device register which holds an unsigned short.  Please define
  a SYMBOL named BUTTONS that cen be used to ACCESS this location.  NOTE this device registers value
  can change UNEXPECTEDLY */
#define BUTTONS (*(vu16*)0x4000130)
  
/* FIXME 5) Define a MACRO named SETMODE that takes in two ints.  These two ints will be the background to enable and the
  mode to set.  And this will set the Display control register to the proper vlaue for us! */
#define SETMODE(BE,MODE) REG_DISPCNT=((BE)|(MODE))

#define BG2_ENABLE (1 << 10)
#define MODE3 3

#define WIDTH 240
#define HEIGHT 160
/* FIXME 5) Define the OFFSET3 Macro here it should take in a position (row column or x y) and give you a raster index */
#define OFFSET3(row, col) (((row)*240)+(col))

/* FIXME 6) Define the RGB Macro here it should take in a red a green and a blue value and return 0bbbbbgggggrrrrr */
#define RGB(r, g, b) ((r) | ((g) << 5) | ((b) << 10))
						/*(that is red in the lowest 5 bits, green in the next 5 bits and blue in the top five bits */
#define RED RGB(31,0,0)
#define GREEN RGB(0,31,0)
#define BLUE RGB(0,0,31)
#define MAGENTA RGB(31,0,31)
#define YELLOW RGB(31,31,0)
#define CYAN RGB(0,31,31)
#define WHITE RGB(31,31,31)
#define BLACK 0


/* Buttons */

#define BUTTON_A      (1<<0)
#define BUTTON_B      (1<<1)
#define BUTTON_SELECT (1<<2)
#define BUTTON_START  (1<<3)
#define BUTTON_RIGHT  (1<<4)
#define BUTTON_LEFT   (1<<5)
#define BUTTON_UP     (1<<6)
#define BUTTON_DOWN   (1<<7)
#define BUTTON_R      (1<<8)
#define BUTTON_L      (1<<9)



#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

extern u16* videoBuffer;
#define DMA_CHANNEL_3 3
#define REG_DMA3SAD         *(vu32*)0x40000D4   /* source address*/
#define REG_DMA3DAD         *(vu32*)0x40000D8  /* destination address*/
#define REG_DMA3CNT         *(vu32*)0x40000DC  /* control register*/
#define DMA_SOURCE_FIXED (2 << 23)
#define DMA_ON (1 << 31)
/* Do not change any of the function prototypes here */
void waitForVBlank(void);
void setPixel(int row, int col, u16 color);
void clearScreen(u16 color);
void drawCursor(Cursor cursor);
/* FIXME Fix this prototype so that it can be used to draw any title screen passed to it */
void drawTitle(const u16* title);
#endif /* MY_LIB_H */
