/**************************************************
	Name: renderer.c							***
	Team: Louis, Chris							***
	Author: Louis Mau/Chris Mah					***
	Purpose: Render functions to be called when ***
	the model is updated. Draws/Renders to the  ***
	screen.										***
												***
												***
***************************************************/
#include "RENDERER.H"

void render(const struct Model *model, UINT8 *base) {


    
}

/*
	Name: render_static_frame
	Purpose: renders the initial frame of the game. All the static objects
			 are rendered here.
	Input: UINT8 *base  - Base pointer for the screen.

*/
void render_static_frame(UINT8 *base) {
	
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
/*
	Name: render_asian_facing_right
	Purpose: Render the Asian bitmap that is looking right at the correct position
	Input: struct Model *model - model to obtain the correct Asian and its x and y.
*/
void render_asian_facing_right(const struct Model *model, UINT32 *base) {
	plot_bitmap_32(base, model->asian1.x, model->asian1.y, asian_facing_right_bitmap, ASIAN_FACING_RIGHT);
}
/*
	Name: render_asian_facing_left
	Purpose: Render the Asian bitmap that is looking left at the correct position.
	Input: struct Model *model - model to obtain the correct Asian and its x and y.
*/
void render_asian_facing_left(const struct Model *model, UINT32 *base) {
    plot_bitmap_32(base, model->asian2.x, model->asian2.y, asian_facing_left_bitmap, ASIAN_FACING_RIGHT);
}
/*
	Name: render_chopsticks_facing_right
	Purpose: Render the chopstick bitmap that is going right at the correct position.
	Input: Chopstick *chopsticks - chopsticks struct to obtain correct x and y.
*/
void render_chopsticks_facing_right(const struct Chopstick *chopsticks, UINT16 *base) {
    plot_bitmap_16(base, chopsticks->x, chopsticks->y, chopsticks_moving_right, CHOPSTICKS);
}
/*
	Name: render_chopsticks_facing_left
	Purpose: Render the chopstick bitmap that is going left at the correct position.
	Input: Chopstick *chopsticks - chopstick struct to obtain correct x and y.
*/
void render_chopsticks_facing_left(const struct Chopstick *chopsticks, UINT16 *base) {
    plot_bitmap_16(base, chopsticks->x, chopsticks->y, chopsticks_moving_left, CHOPSTICKS);
}

void render_alive_chopsticks(const struct Model *model,int asian,UINT16 *base) {
	int i;
	struct Chopsticks chopsticks[3];
	
	for(i = 0; i < 3; i++)
	{
		if (chopsticks[i]->isThrown && asian == 1)
		{
			asian = model->asian1;
			chopsticks[3] = asian1->chopsticks;
			render_chopsticks_facing_right(chopsticks[i],base);
		}
		else
		{
			asian = model->asian2;
			chopsticks[3] = asian2->chopsticks;
			render_chopsticks_facing_left(chopsticks[i],base);
		}
	}
	
}

/*
	Name: clrBitmap32
	Purpose: Clears a 32x32 bitmap given it's position and the base pointer.
*/
void clrBitmap32(UINT32 *base,int x, int y)
{
	clrRgn32(base,x,y,1,32);
}
/*
	Name: clrBitmap16
	Purpose: Clears a 16x16 bitmap give it's position and the base pointer.
*/
void clrBitmap16(UINT16 *base, int x, int y)
{
	clrRgn16(base,x,y,1,16);
}