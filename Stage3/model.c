#include "model.h"
#include <stdio.h>
void initilizeAsian(struct Asian *asian);
int main()
{

	/*struct Asian asian2 = {639,399,5,1,true,1,-1};*/
	struct Chopstick chopsticks[3] = {{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}};
	struct Asian asian1 = {0,0,5,1,true,1,-1,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}};
	struct Obstruction obs1[3] = {{40,40},{40,60},{40,80}};
	struct Obstruction obs2[3] = {{340,40},{340,60},{340,80}};
	struct PlayerInfo pi = {0,368};
	
	printf("%i,\n",asian1.hor_delta);
	printf("%i,\n",asian1.ver_delta);
	resetAsianDeltas(&asian1);
	/*printf("%i,\n",asian2.hor_delta);*/
/* 	printf("%i,\n",asian2.ver_delta);*/	
	printf("%i,\n",obs1[2].y);

	return 0;
}

void resetAsianDeltas(struct Asian *asian)
{
	asian->hor_delta = 0;
	asian->ver_delta = 0;
	
	return;
}

void asiannMoveRight(struct Asian *asian)
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
	bool canThrow = false;
	if(asian->canThrow == true)
	{
		asian->canThrow = false;
		while(i<3 && canThrow == false)
		{
			if( asian->chopsticks[i].isThrown == false)
			{
				spawnChopstick(&asian->chopsticks[i],asian);
				canThrow = true;
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
	
	return;
}

