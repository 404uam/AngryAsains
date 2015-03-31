#include <osbind.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

typedef unsigned int UINT16;

void plot_bitmap_16(UINT16 *base, int x, int y,
                    const UINT16 *bitmap, unsigned int height);

#define INVADER_HEIGHT 16

const UINT16 invader_bitmap[INVADER_HEIGHT] =
{
	0x0000,
	0x0810,
	0x0810,
	0x0420,
	0x0240,
	0x1FF8,
	0x2004,
	0x4662,
	0x4002,
	0x43C2,
	0x2424,
	0x1008,
	0x0FF0,
	0x0240,
	0x0E70,
	0x0000
};

int main()
{
	UINT16 *base = Physbase();
	int x, y;

	for (y = 0; y < SCREEN_HEIGHT; y += INVADER_HEIGHT)
		for (x = 0; x < SCREEN_WIDTH; x += 16)
			plot_bitmap_16(base, x, y,
			               invader_bitmap, INVADER_HEIGHT);

	return 0;
}

void plot_bitmap_16(UINT16 *base, int x, int y,
                    const UINT16 *bitmap, unsigned int height)
{
	int i = 0;
	while(i < height)
	{
		base = bitmap[i];
	}
}
