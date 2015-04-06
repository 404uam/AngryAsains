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