#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	int x, y;

	clrScrn(base);
	plot_ver_line(base,320,0,640);
	paintRgn(base,0,320,20,80);
	plot_bitmap_32(base, 0, 130, asian_facing_right_bitmap, ASIAN_FACING_RIGHT);
	plot_bitmap_32(base, 608, 130, asian_facing_left_bitmap, ASIAN_FACING_RIGHT);
	plot_bitmap_32(base, 96, 32, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32(base, 192, 130, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32(base, 96, 224, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32(base, 512, 32, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32(base, 416, 130, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32(base, 512, 224, trashcan_bitmap, TRASHCAN);

	Cconin();


	return 0;
}