#include <osbind.h>
#include <stdio.h>
#include <vt52.h>
#include "events.h"


#define RETURN	0x001C000DL
#define LEFT 	0x001E0061L
#define RIGHT 	0x00200064L
#define DOWN 	0x001F0073L
#define UP 		0x00110077L
#define SPACE 	0x00390020L


void keyPress(struct Model *model, bool *stop)
{
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
					*stop = true;
					break;
			default:
					break;
			
		}
		
	}
	return;
}

void clock_tick(struct Model *model)
{
	asianMoveModel(&model->asian1);
	
	time = 0;
}