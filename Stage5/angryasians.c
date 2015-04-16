#include "renderer.h"
#include <osbind.h>
#include <vt52.h>

#define RETURN	0x001C000DL
#define LEFT 	0x001E0061L
#define RIGHT 	0x00200064L
#define DOWN 	0x001F0073L
#define UP 		0x00110077L
#define SPACE 	0x00390020L

UINT32 getTime();

int main()
{
	void *base = Physbase();
	UINT32 timeThen, timeNow, timeElapsed;

	modelType model = {{0,0,5,1,true,0,0,{{310,50,1,1,false},{50,50,1,1,false},{0,0,1,1,false}}}, 
					   {608,288,5,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, 
					   {{40,40},{40,60},{40,80}},											
					   {{340,40},{340,60},{340,80}},										
					   {0,368}};

	render_static_frame(base);
	render_asian_facing_right(&model,base);
	render_asian_facing_left(&model,base);

	bool quit = false;
	timeThen = getTime();

	while(quit) 
	{
		timeNow = getTime();
		timeElapsed = timeNow - timeThen;

		long input;
	
		fflush (stdout);

		if(Cconis())
		{
			input = Cnecin();
		
			switch(input)
			{
				case UP:
						asianMoveUp(&model->asian1);			
						break;
				case DOWN: 
						asianMoveDown(&model->asian1);
						break;
				case LEFT:
						asianMoveLeft(&model->asian1);
						break;
				case RIGHT:
						asianMoveRight(&model->asian1);
						break;
				case SPACE:
						time = 1;
						break;
				case RETURN:
						printf("OUT");
						quit = true;
						break;
				default:
						break;
			}
		}

		if (timeElapsed > 0)
		{
			asianMoveModel(&model->asian1);

			render_static_frame(base);
			render_asian_facing_right(&model,base);
			render_asian_facing_left(&model,base);
			
			timeThen = timeNow;
		}
	}

	return 0;
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