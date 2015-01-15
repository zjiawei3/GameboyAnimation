#ifndef TEXT_H
#define TEXT_H

extern const unsigned char fontdata[1536];
#define TEXT_WIDTH 6
#define TEXT_HEIGHT 8

void drawChar(int row, int col, char toDraw, u16 color);
void drawString(int row, int col, char str[], u16 color);

#endif
