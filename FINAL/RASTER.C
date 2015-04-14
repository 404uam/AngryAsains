#include "raster.h"

void clrScrn(UINT32 *base)
{
	int i;
	int maxPixel = (SCREEN_WIDTH * SCREEN_HEIGHT)/32;

	for(i = 0; i < maxPixel; i++)
	{
		*(base + i) &= 0;
	}
}

void plot_bitmap_16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height) {
	int i;
	int offset = x % 16;

	base += (y * 40) + (x / 16);

	if(x >= 0 && (x + 1) < SCREEN_WIDTH && y >= 0 && (y + height) < SCREEN_HEIGHT) {
		for(i = 0;i < height;i++) {
			*(base + (i * 40)) ^= bitmap[i] >> offset;
			if(offset > 0) {
				base++;
				*(base + (i * 40)) ^= bitmap[i] << (15 - offset);
				base--;
			}
		}
	}
}

void plot_bitmap_32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height) {
	int i;
	int offset = x % 32;

	base += (y * 20) + (x / 32);

	if(x >= 0 && (x + 1) < SCREEN_WIDTH && y >= 0 && (y + height) < SCREEN_HEIGHT) {
		for(i = 0;i < height;i++) {
			*(base + (i * 20)) ^= bitmap[i] >> offset;
			if(offset > 0) {
				base++;
				*(base + (i * 20)) ^= bitmap[i] << (31 - offset);
				base--;
			}
		}
	}
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
				*(base + i*20 + j) = 0xFFFFFFFF;
			}
		}
	}
}
