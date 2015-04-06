/*
Name: Model.c
Team: Louis, Chris
Author: Louis Mau
Purpose: Function declaration for the model. Functions for the Asians and chopsticks.
		Asians moving(collision detecting) and resetting deltas functions
		Chopsticks moving and collision detecting
*/
#include "model.h"
#include <stdio.h>

/*
Name: resetAsianDeltas()
Purpose: reset the deltas of the Asian after moving.
*/
void resetAsianDeltas(struct Asian *asian)
{
	asian->hor_delta = 0;
	asian->ver_delta = 0;
	
	return;
}
/*
Name: asianMoveRight
Purpose: changes the delta for the asian to move right ->
*/
void asianMoveRight(struct Asian *asian)
{
	asian->hor_delta = 1;
	
	return;
}
/*
Name: asianMoveLeft
Purpose: changes the delta for the asian to move left <-
*/
void asianMoveLeft(struct Asian *asian)
{
	asian->hor_delta = -1;
	
	return;
}
/*
Name: asianMoveUp
Purpose: change the delta for the asian to move up ^
*/
void asianMoveUp(struct Asian *asian)
{
	asian->ver_delta = 1;
	
	return;
}
/*
Name: asianMoveDown
Purpose: change the delta for the asian to move down v
*/
void asianMoveDown(struct Asian *asian)
{
	asian->ver_delta = -1;
	
	return;
}
/*
Name: asianMoveModel
Purpose: actually update the model by adding the deltas
*/
void asianMoveModel(struct Asian *asian)
{
	asian->x += asian->hor_delta;
	asian->y += asian->ver_delta;
	
	resetAsianDeltas(asian);
	
	/* TODO COLLISION DETECTION */
		
	return;
}
/*
Name: asianThrowChopstick
Purpose: 
*/
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

