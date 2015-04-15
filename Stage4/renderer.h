#ifndef	RENDERER_H
#define RENDERER_H

#include <stdlib.h>
#include <stdio.h>

#include "model.h"
#include "types.h"
#include "raster.h"
#include "BITMAPS.H"

extern void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
extern void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);
extern void clrScrn(UINT32 *base);
extern void plot_ver_line(UINT8 *base,int x, int y, int length);
extern void paintRgn(UINT32 *base,int originX, int originY, int width, int height);

void render(const struct Model *model, UINT8 *base);
void render_frame(UINT8 *base);
void render_asian_facing_right(const struct Asian *asian, UINT32 *base);
void render_asian_facing_left(const struct Asian *asian, UINT32 *base);
void render_chopsticks_facing_right(const struct Chopstick *chopsticks, UINT16 *base);
void render_chopsticks_facing_left(const struct Chopstick *chopsticks, UINT16 *base);
/*void render_obstuction(const struct Model *model, UINT8 *base);*/

#endif