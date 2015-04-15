#ifndef RASTER_H
#define RASTER_H
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define BITMAP32 128

#define SOLID  0xFFFF
#define DASHED 0xF0F0

#define XOR 2

#include <osbind.h>
#include "types.h"

extern const UINT32 chopsticks_moving_left_bitmap[15];

void plot_pixel(UINT8 *base, int x, int y);
void plot_ver_line(UINT8 *base,int x, int y, int length);
void clrScrn(UINT32 *base);
void paintRgn(UINT32 *base,int originX, int originY, int width, int height);

#endif
