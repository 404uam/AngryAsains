#ifndef RASTER_H
#define RASTER_H

#include "types.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);
void clrScrn(UINT32 *base);

#define ASIAN_FACING_RIGHT 32
#define TRASHCAN 32
#define CHOPSTICKS 16

#endif