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
	printf("Moved Right");
	return;
}
/*
Name: asianMoveLeft
Purpose: changes the delta for the asian to move left <-
*/
void asianMoveLeft(struct Asian *asian)
{
	asian->hor_delta = -1;
	printf("Moved Left");
	
	return;
}
/*
Name: asianMoveUp
Purpose: change the delta for the asian to move up ^
*/
void asianMoveUp(struct Asian *asian)
{
	asian->ver_delta = 1;
	printf("Moved up");
	
	return;
}
/*
Name: asianMoveDown
Purpose: change the delta for the asian to move down v
*/
void asianMoveDown(struct Asian *asian)
{
	asian->ver_delta = -1;
	printf("Moved Down");
	
	return;
}
/*
Name: asianMoveModel
Purpose: actually update the model by adding the deltas
*/
void asianMoveModel(struct Asian *asian)
{
	/* TODO COLLISION DETECTION */
	if(asian->x + asian->hor_delta > (MIDDLEOFSCREEN-32))
	{
		resetAsianDeltas(asian);
	}
	asian->x += asian->hor_delta;
	asian->y += asian->ver_delta;
	
	printf("\nThe position of asian is (%d,%d)\n",asian->x,asian->y);
	
	resetAsianDeltas(asian);

	return;
}
/*
Name: asianThrowChopstick
Purpose: Asian will throw the chopstick and have the checks if there are any available chopsticks to throw.
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
/*
Name: spawnChopstick
Purpose: Puts the chopstick to start where the asian is currently and then count it as being thrown
*/

void spawnChopstick(struct Chopstick *chopstick,struct Asian *asian)
{
	chopstick->x = asian->x;
	chopstick->y = asian->y;
	chopstick->isThrown = true;
	
	return;
}
/*
Name: chopstickMove
Purpose: Actually move the coordinates of the chopsticks
Assumptions: Assuming the direction of the chopsticks are correct and correspond to the asian shooting them.
*/
void chopstickMove(struct Chopstick *chopstick)
{
	chopstick->x += chopstick->direction;
	
	/* Collision detection todo*/
	/*Peusdo code*/
	/* if collide with anything ...*/
	/* set isThrown to false so you can use it again */
	return;
}

