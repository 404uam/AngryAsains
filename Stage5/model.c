/*
Name: Model.c
Team: Louis, Chris
Author: Louis Mau
Purpose: Function declaration for the model. Functions for the Asians and chopsticks.
		Asians moving(collision detecting) and resetting deltas functions
		Chopsticks moving and collision detecting
*/
#include "model.h"
#include <osbind.h>
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
	asian->ver_delta = -1;
	
	return;
}
/*
Name: asianMoveDown
Purpose: change the delta for the asian to move down v
*/
void asianMoveDown(struct Asian *asian)
{
	asian->ver_delta = 1;
	
	return;
}
/*
Name: asianMoveModel
Purpose: actually update the model by adding the deltas
*/
void asianMoveModel(struct Asian *asian,const struct Model *model,int type)
{
	int i;
	/* TODO COLLISION DETECTION */
	/*Checks middle line of screen */
	if(type == 1) 
	{
		if(asian->x + asian->hor_delta > (MIDDLEOFSCREEN-32))
		{
			resetAsianDeltas(asian);
		}
		/*Checks playerinfo area*/
		else if(asian->y + asian->ver_delta > (model->pi.y - 32)) 
		{
			resetAsianDeltas(asian);
		}
		else{
			for(i = 0; i < 3; i++)		/* Checks through all the obstacles on the side*/
				{
					/*Are you trying to move RIGHT in to the trash*/
					if( model->obs1[i].y == (asian->y+ asian->ver_delta)  && model->obs1[i].x-32 == asian->x &&
						asian->x + asian->hor_delta > model->obs1[i].x-32)
						{
							resetAsianDeltas(asian);
						}
					/*Are you trying to move LEFT into the trash?*/	
					if(	model->obs1[i].y == (asian->y + asian->ver_delta)  && model->obs1[i].x+32 == asian->x &&
						asian->x + asian->hor_delta < model->obs1[i].x+32)
						{
							resetAsianDeltas(asian);
						}
					/*Are you trying to move DOWN into the trash?*/
					if(	model->obs1[i].x == (asian->x + asian->hor_delta) && model->obs1[i].y-32 == asian->y &&
						asian->y + asian->ver_delta > model->obs1[i].y-32)
						{
							resetAsianDeltas(asian);
						}
					/*Are you trying to move UP in to the trashcan??*/
					if(	model->obs1[i].x == (asian->x + asian->hor_delta) && model->obs1[i].y+32 == asian->y &&
						asian->y + asian->ver_delta < model->obs1[i].y+32)
						{
							resetAsianDeltas(asian);
						}
						
				}
			}
	} else {
		if(asian->x + asian->hor_delta < (MIDDLEOFSCREEN+32))
		{
			resetAsianDeltas(asian);
		}
		/*Checks playerinfo area*/
		else if(asian->y + asian->ver_delta > (model->pi.y - 32)) 
		{
			resetAsianDeltas(asian);
		}
		else{
			for(i = 0; i < 3; i++)		/* Checks through all the obstacles on the side*/
				{
					/*Are you trying to move RIGHT in to the trash*/
					if( model->obs2[i].y == (asian->y+ asian->ver_delta)  && model->obs2[i].x-32 == asian->x &&
						asian->x + asian->hor_delta > model->obs2[i].x-32)
						{
							resetAsianDeltas(asian);
						}
					/*Are you trying to move LEFT into the trash?*/	
					if(	model->obs2[i].y == (asian->y + asian->ver_delta)  && model->obs2[i].x+32 == asian->x &&
						asian->x + asian->hor_delta < model->obs2[i].x+32)
						{
							resetAsianDeltas(asian);
						}
					/*Are you trying to move DOWN into the trash?*/
					if(	model->obs2[i].x == (asian->x + asian->hor_delta) && model->obs2[i].y-32 == asian->y &&
						asian->y + asian->ver_delta > model->obs2[i].y-32)
						{
							resetAsianDeltas(asian);
						}
					/*Are you trying to move UP in to the trashcan??*/
					if(	model->obs2[i].x == (asian->x + asian->hor_delta) && model->obs2[i].y+32 == asian->y &&
						asian->y + asian->ver_delta < model->obs2[i].y+32)
						{
							resetAsianDeltas(asian);
						}
						
				}
			}
	}
	
	asian->x += asian->hor_delta*32;
	asian->y += asian->ver_delta*32;
	
	resetAsianDeltas(asian);

	return;
}
/*
Name: asianThrowChopstick
Purpose: Asian will throw the chopstick and have the checks if there are any available chopsticks to throw.
*/
void asianThrowChopstick(struct Asian *asian)
{
	int i = 0;
	bool canThrowChop = false;
	if(asian->canThrow == true)
	{
		/*asian->canThrow = false;*/
		while(i<3 && canThrowChop == false)
		{
			if( asian->chopsticks[i].isThrown == false)
			{
				spawnChopstick(&asian->chopsticks[i],asian);
				canThrowChop = true;
			}
			i++;
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
	/* Addding 32 and 16 to shoot from the middle of the asian */
	chopstick->x = asian->x;
	chopstick->y = asian->y + 16;
	chopstick->isThrown = true;
	
	return;
}
/*
Name: chopstickMove
Purpose: Actually move the coordinates of the chopsticks
Assumptions: Assuming the direction of the chopsticks are correct and correspond to the asian shooting them.
*/
void chopstickMove(struct Chopstick *chopstick,struct Model *model)
{
	int i;
	chopstick->x += chopstick->direction*16;
	
	/* Collision detection todo*/
	/*Peusdo code*/
	/* if collide with anything ...*/
	/* set isThrown to false so you can use it again */
	if(chopstick->x + chopstick->direction*16 > SCREEN_WIDTH)
	{
		chopstick->isThrown = false;
	}
	else
	{
		for(i = 0; i< 3; i++)
		{
			if(chopstick->x + chopstick->direction*16 == model->obs1[i].x &&
			   chopstick->y >= model->obs1[i].y && chopstick->y <= model->obs1[i].y+16)
			{
				chopstick->isThrown = false;
			}
			if(chopstick->x + chopstick->direction*16 == model->obs2[i].x &&
			   chopstick->y >= model->obs2[i].y && chopstick->y <= model->obs2[i].y+16)
			{
				chopstick->isThrown = false;
			}
		}
	
	}
	
	return;
}

void moveAliveChopsticks(struct Asian *asian,struct Model *model)
{
	int i;

	for(i = 0; i < 3; i++)
	{
		if (asian->chopsticks[i].isThrown == true)
		{
			chopstickMove(&asian->chopsticks[i],model);
		}
	}
}

void updateModel(struct Model *model)
{
	asianMoveModel(&model->asian1,model,1);
	asianMoveModel(&model->asian2,model,2);
	moveAliveChopsticks(&model->asian1,model);
	moveAliveChopsticks(&model->asian2,model);
}

void ai(struct Model *model)
{
	if(model->asian1.y < model->asian2.y) {
		asianMoveUp(&model->asian2);
	} else if(model->asian1.y > model->asian2.y) {
		asianMoveDown(&model->asian2);
	}

	if(model->asian1.y+32 == model->asian2.y || model->asian1.y-32 == model->asian2.y)
		asianThrowChopstick(&model->asian2);
	/*
	if(model->asian2.x - model->asian1.x > 200) {
		asianMoveLeft(&model->asian2);
	} else if(model->asian2.x - model->asian2.x < 200) {
		asianMoveRight(&model->asian2);
	}
	*/
}
