#include "renderer.h"
#include <stdio.h>

void render(const struct Model *model, UINT8 *base) {
    
}

void render_frame(UINT8 *base) {
	
	
	
}

void render_asian_facing_right(const struct Asian *asian, UINT32 *base) {
	plot_bitmap_32(base, asian->x, asian->y, asian_facing_left_bitmap, ASIAN_FACING_RIGHT);
}

void render_asian_facing_left(const struct Asian *asian, UINT32 *base) {
    plot_bitmap_32(base, asian->x, asian->y, asian_facing_left_bitmap, ASIAN_FACING_RIGHT);
}

void render_chopsticks_facing_right(const struct Chopsticks *chopsticks, UINT8 *base) {
    plot_bitmap_16(base, chopsticks->x, chopsticks->y, chopsticks_moving_left, CHOPSTICKS);
}

void render_chopsticks_facing_left(const struct Chopsticks *chopsticks, UINT8 *base) {
    plot_bitmap_16(base, chopsticks->x, chopsticks->y, chopsticks_moving_left, CHOPSTICKS);
}

void render_obstuction(const struct Obstruction *obstruction, UINT8 *base) {
    plot_bitmap_32(base, obstruction->x, obstruction->y, trashcan_bitmap, TRASHCAN);
}