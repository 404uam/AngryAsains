#include "angry.h"
#include <osbind.h>
#include <vt52.h>
#include "TYPES.H"

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
	bool quit = false;
	long input;
	

	modelType model = {{0,0,5,1,true,0,0,{{310,50,1,1,false},{50,50,1,1,false},{0,0,1,1,false}}}, 
					   {608,288,5,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, 
					   {{96,32},{192,128},{96,224}},											
					   {{512,32},{416,128},{512,224}},										
					   {0,320}};

	render_static_frame(base);
	render_asian_facing_right(&model,base);
	render_asian_facing_left(&model,base);

	timeThen = getTime();
	
	while(quit == false) 
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
						break;
				case DOWN: 
						asianMoveDown(&model.asian1);
						break;
				case LEFT:
						asianMoveLeft(&model.asian1);
						break;
				case RIGHT:
						asianMoveRight(&model.asian1);
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
			asianMoveModel(&model.asian1,&model);

			/*clrBitmap32(base,model.asian1.x,model.asian1.y);
			clrBitmap32(base,model.asian2.x,model.asian2.y);*/
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