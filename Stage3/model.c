#include "model.h"
#include <stdio.h>
void initilizeAsian(struct Asian *asian);
int main()
{
	struct Asian asian1 = {0,0,5,1,true,1,-1};
	struct Asian asian2 = {639,399,5,1,true,1,-1};
	struct Obstruction obs1[3] = {{40,40},{40,60},{40,80}};
	struct Obstruction obs2[3] = {{340,40},{340,60},{340,80}};
	struct PlayerInfo pi = {0,368};
	
	printf("%i,\n",asian1.hor_delta);
	printf("%i,\n",asian1.ver_delta);
	resetAsianDeltas(&asian1);
	printf("%i,\n",asian2.hor_delta);
	printf("%i,\n",asian2.ver_delta);
	printf("%i,\n",obs1[2].y);

	return 0;
}

void resetAsianDeltas(struct Asian *asian)
{
	asian->hor_delta = 0;
	asian->ver_delta = 0;
	
	return;
}

void asainMoveRight(struct Asian *asian)
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
		
}

void chopstickMove(struct Chopstick *chopstick)
{
	chopstick->x += chopstick->direction;
	
	return;
}

