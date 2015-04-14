#include <osbind.h>
#include <stdio.h>
#include <vt52.h>
#include "events.h"

#define RETURN	0x001C000DL
#define LEFT 	0x001E0061L
#define RIGHT 	0X00200064L
#define DOWN 	0X001F0073L
#define UP 		0X00110077L


void keyPress(struct Model *model,bool *stop)
{
	long input;
	printf("\033E\033Y*H");
	
	
	fflush(stdout);
	if(Cconis())
	{
		input = Cnecin();
		
		switch(input)
		{
			case UP:
					asianMoveUp(model->asian1);
					fflush(stdout);
					break;
			case DOWN: 
					asianMoveDown(model->asian1);
					fflush(stdout);
					break;
			case LEFT:
					asianMoveLeft(model->asian1);
					fflush(stdout);
					break;
			case RIGHT:
					asianMoveRight(model->asian1);
					fflush(stdout);
					break;
			case SPACE:
					asianThrowChopstick(model->asian1.chopticks)
					fflush(stdout);
					break;
			case RETURN:
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
	asianMoveModel(model->asian1.chopsticks);
	
	time = 0;
}