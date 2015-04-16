#include "angry.h"
#include <osbind.h>
#include <vt52.h>
#include "TYPES.H"
#include <string.h>

#define RETURN	0x001C000DL
#define LEFT 	0x001E0061L
#define RIGHT 	0x00200064L
#define DOWN 	0x001F0073L
#define UP 		0x00110077L
#define SPACE 	0x00390020L

UINT32 getTime();

/*
UINT8 buffer[32256];
UINT8 static_buffer[32256];
*/

int main()
{
	/*
	void *back = buffer;
	void *background = static_buffer;
	*/
	void *base = Physbase();
	UINT32 timeThen, timeNow, timeElapsed;
	bool quit = false;
	long input;

	modelType model = {{0,0,3,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, 
					   {608,288,3,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, 
					   {{96,32},{192,128},{96,224}},											
					   {{512,32},{416,128},{512,224}},										
					   {0,320}};
					   
	/*printf("/033f/n");*/
	/*fflush(stdout);*/
	
	/*render_static_frame(back);*/
	render_static_frame(base,&model);
	render_asian_facing_right(&model,base);
	render_asian_facing_left(&model,base);

	timeThen = getTime();
	
	while(quit == false && gameOver(&model)==false) 
	{
		timeNow = getTime();
		timeElapsed = timeNow - timeThen;
	
		fflush (stdout);

		if(Cconis())
		{
			input = Cnecin();
		
			switch(input)
			{
				case UP:
						asianMoveUp(&model.asian1);		
						clrBitmap32(base,model.asian1.x,model.asian1.y);
						break;
				case DOWN: 
						asianMoveDown(&model.asian1);
						clrBitmap32(base,model.asian1.x,model.asian1.y);
						break;
				case LEFT:
						asianMoveLeft(&model.asian1);
						clrBitmap32(base,model.asian1.x,model.asian1.y);
						break;
				case RIGHT:
						asianMoveRight(&model.asian1);
						clrBitmap32(base,model.asian1.x,model.asian1.y);
						break;
				case SPACE:
						asianThrowChopstick(&model.asian1);
						break;
				case RETURN:
				/*
						Setscreen(-1,base,-1);
						Vsync();
				*/
						printf("OUT");
						quit = true;
						break;
				default:
						break;
			}
		}

		if (timeElapsed > 0)
		{
			/*memcpy(base, background, 32257);*/
			unrender_alive_chopsticks(&model.asian1,base);
			unrender_alive_chopsticks(&model.asian2,base);
			ai(&model);
			clrBitmap32(base,model.asian2.x,model.asian2.y);
			updateModel(&model);
			


			render_alive_chopsticks(&model.asian1,1,base);
			render_alive_chopsticks(&model.asian2,2,base);
			render_asian_facing_right(&model,base);
			render_asian_facing_left(&model,base);


			/*
			Setscreen(-1,back,-1);
			Vsync();
			*/

			timeThen = timeNow;
		}
	}

	return 0;
}

bool gameOver(struct Model *model){
	bool gameOver = false;
	if(model->asian1.lives < 1 || model->asian2.lives < 1)
	{	
		gameOver = true;
	}
	return gameOver;
}

UINT32 getTime() {
	long *timer = (long *)0x462;
	long timeNow;
	long old_ssp;
	old_ssp = Super(0); /* enter privileged mode */
	timeNow = *timer;
	Super(old_ssp); /* exit privileged mode as soon as possible */
	return timeNow;
}