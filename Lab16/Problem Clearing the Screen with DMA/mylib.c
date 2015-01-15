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
	while(SCANLINECOUNTER < 160);
}

void drawLine(int x1, int y1, int x2, int y2, u16 color)
{
    int deltax = abs(x2 - x1);
    int deltay = abs(y2 - y1);

    int x = x1;
    int y = y1;

    int xinc1, xinc2, yinc1, yinc2;
    int den, num, numadd, numpixels;
    int curpixel;

    if (x2 >= x1)
    {
        xinc1 = 1;
        xinc2 = 1;
    }
    else
    {
        xinc1 = -1;
        xinc2 = -1;
    }

    if (y2 >= y1)
    {
        yinc1 = 1;
        yinc2 = 1;
    }
    else
    {
        yinc1 = -1;
        yinc2 = -1;
    }

    if (deltax >= deltay)
    {
        xinc1 = 0;
        yinc2 = 0;
        den = deltax;
        num = deltax / 2;
        numadd = deltay;
        numpixels = deltax;
    }
    else
    {
        xinc2 = 0;
        yinc1 = 0;
        den = deltay;
        num = deltay / 2;
        numadd = deltax;
        numpixels = deltay;
    }

    for (curpixel = 0; curpixel <= numpixels; curpixel++)
    {
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            setPixel(x, y, color);

        num += numadd;
        if (num >= den)
        {
            num -= den;
            x += xinc1;
            y += yinc1;
        }
        x += xinc2;
        y += yinc2;
    }
}
