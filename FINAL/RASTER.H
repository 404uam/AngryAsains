#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include <stdlib.h>
#include <stdio.h>
#include "BITMAPS.H"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);
void clrScrn(UINT32 *base);
void plot_ver_line(UINT8 *base,int x, int y, int length);
void paintRgn(UINT32 *base,int originX, int originY, int width, int height);
void clrRgn32(UINT32 *base,int x, int y, int width, int height);
void clrRgn16(UINT16 *base,int x, int y, int width, int height);

#endif