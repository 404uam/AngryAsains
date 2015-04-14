#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	int x, y;

	clrScrn(base);
	plot_bitmap_32(base, 50, 50, asian_facing_right_bitmap, ASIAN_FACING_RIGHT);
	plot_bitmap_32(base, 100, 50, asian_facing_left_bitmap, ASIAN_FACING_RIGHT);
	plot_bitmap_32(base, 150, 50, trashcan_bitmap, TRASHCAN);
	plot_bitmap_16(base, 200, 50, chopsticks_moving_left, CHOPSTICKS);
	plot_bitmap_16(base, 250, 50, chopsticks_moving_right, CHOPSTICKS);
	

	return 0;
}