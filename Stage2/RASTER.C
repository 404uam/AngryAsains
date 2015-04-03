#include "raster.h"

const UINT32 chopsticks_moving_left_bitmap[15] = {
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x000C,
0x7F0C,
0x7F20,
0x0002,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
0x0000,
};

void plot_pixel(UINT8 *base, int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7);
}

void plot_ver_line(UINT8 *base, int x, int y, int length)
{
	int i;
	int sum = 0;
	
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT){
		base +=  y * 80+ (x >> 3);
		
		for (i = 0; i < length; i++)
		{
			if((sum+y) <= SCREEN_HEIGHT){
				*(base + i*80) |= 1 << 7 - (x & 7);
				sum++;
				}
		}
	}

}

void clrScrn(UINT32 *base)
{
	int i;
	int maxPixel = (SCREEN_WIDTH * SCREEN_HEIGHT)/32;
	for (i = 0; i < maxPixel; i++)
	{
		*(base + i) &= 0;
	}
}

void paintRgn(UINT32 *base,int x, int y, int width, int height)
{
	int i;
	int j;
	
		if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT){
			base +=  y * 20+ (x >> 5);
	
		for(i = 0; i < height; i++)
		{
			for(j = 0; j < width; j++)
			{
				*(base + i*20 + j) |= 0xFFFFFFFF;
			}
		}
	}
}