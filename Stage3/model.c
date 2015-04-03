#include "model.h"
#include <stdio.h>

void resetAsianDeltas(struct Asian *asian)
{
	asian->hor_delta = 0;
	asian->ver_delta = 0;
	
	return;
}

void asianMoveRight(struct Asian *asian)
{
	asian->hor_delta = 1;
	
	return;
}

void asianMoveLeft(struct Asian *asian)
{
	asian->hor_delta = -1;
	
	return;
}

void asianMoveUp(struct Asian *asian)
{
	asian->ver_delta = 1;
	
	return;
}

void asianMoveDown(struct Asian *asian)
{
	asian->ver_delta = -1;
	
	return;
}

void asianMoveModel(struct Asian *asian)
{
	asian->x += asian->hor_delta;
	asian->y += asian->ver_delta;
	
	resetAsianDeltas(asian);
	
	/* TODO COLLISION DETECTION */
		
	return;
}

void asianThrowChopstick(struct Asian *asian)
{
	int i;
	bool canThrowChop = false;
	if(asian->canThrow == true)
	{
		asian->canThrow = false;
		while(i<3 && canThrowChop == false)
		{
			if( asian->chopsticks[i].isThrown == false)
			{
				spawnChopstick(&asian->chopsticks[i],asian);
				canThrowChop = true;
			}
		}
	}
	
	return;
}

void spawnChopstick(struct Chopstick *chopstick,struct Asian *asian)
{
	chopstick->x = asian->x;
	chopstick->y = asian->y;
	chopstick->isThrown = true;
	
	return;
}

void chopstickMove(struct Chopstick *chopstick)
{
	chopstick->x += chopstick->direction;
	
	/* Collision detection todo*/
	/*Peusdo code*/
	/* if collide with anything ...*/
	/* set isThrown to false so you can use it again */
	return;
}

