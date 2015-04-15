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


void keyPress(struct Model *model,bool *stop)
{
	long input;
	
	printf("\033E\033Y*H");
	fflush (stdout);
	
	if(Cconis())
	{
		input = Cnecin();
		
		switch(input)
		{
			case UP:
					asianMoveUp(&model->asian1);
					printf("Moved up");
					fflush(stdout);
					break;
			case DOWN: 
					asianMoveDown(&model->asian1);
					printf("Moved Down");
					fflush(stdout);
					break;
			case LEFT:
					asianMoveLeft(&model->asian1);
					printf("Moved Left");
					fflush(stdout);
					break;
			case RIGHT:
					asianMoveRight(&model->asian1);
					printf("Moved Right");
					fflush(stdout);
					break;
			case SPACE:
					time = 1;
					printf("Time step");
					fflush(stdout);
					break;
			case RETURN:
					printf("OUT");
					stop = true;
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