#include "RENDERER.H"

void render(const struct Model *model, UINT8 *base) {


    
}

void render_frame(UINT8 *base) {
	
	clrScrn((UINT32*)base);
	paintRgn((UINT32*)base,0,320,20,80);
	plot_ver_line(base,320,0,640);
	
	plot_bitmap_32((UINT32*)base, 96, 32, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32((UINT32*)base, 192, 130, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32((UINT32*)base, 96, 224, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32((UINT32*)base, 512, 32, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32((UINT32*)base, 416, 130, trashcan_bitmap, TRASHCAN);
	plot_bitmap_32((UINT32*)base, 512, 224, trashcan_bitmap, TRASHCAN);
	
}

void render_asian_facing_right(const struct Model *model, UINT32 *base) {
	plot_bitmap_32(base, model->asian1.x, model->asian1.y, asian_facing_right_bitmap, ASIAN_FACING_RIGHT);
}

void render_asian_facing_left(const struct Model *model, UINT32 *base) {
    plot_bitmap_32(base, model->asian2.x, model->asian2.y, asian_facing_left_bitmap, ASIAN_FACING_RIGHT);
}

void render_chopsticks_facing_right(const struct Chopstick *chopsticks, UINT16 *base) {
    plot_bitmap_16(base, chopsticks->x, chopsticks->y, chopsticks_moving_right, CHOPSTICKS);
}

void render_chopsticks_facing_left(const struct Chopstick *chopsticks, UINT16 *base) {
    plot_bitmap_16(base, chopsticks->x, chopsticks->y, chopsticks_moving_left, CHOPSTICKS);
}

/*void render_obstuction(const struct Model *model, UINT8 *base) {
    plot_bitmap_32(base, obstruction->x, obstruction->y, trashcan_bitmap, TRASHCAN);
}*/

void clrBitmap32(UINT32 *base,int x, int y)
{
	clrRgn(base,x,y,1,32);
}