#include "renderer.h"
#include <stdio.h>

plot_bitmap_32(base, 50, 50, asian_facing_right_bitmap, ASIAN_FACING_RIGHT);
	plot_bitmap_32(base, 100, 50, asian_facing_left_bitmap, ASIAN_FACING_RIGHT);
	plot_bitmap_32(base, 150, 50, trashcan_bitmap, TRASHCAN);
	plot_bitmap_16(base, 200, 50, chopsticks_moving_left, CHOPSTICKS);
	plot_bitmap_16(base, 250, 50, chopsticks_moving_right, CHOPSTICKS);

void render(const struct Model *model, UINT8 *base) {

}

void render_asian(const struct Asian *asian, UINT32 *base) {
	plot_bitmap_32(base, asian->x, asian->y, asian_facing_left_bitmap, ASIAN_FACING_RIGHT);
}

void render_chopsticks(const struct Model *model, UINT8 *base) {

}

void render_obstuction(const struct Model *model, UINT8 *base) {

}