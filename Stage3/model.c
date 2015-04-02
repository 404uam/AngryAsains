#include "model.h"
#include <stdio.h>
void initilizeAsian(struct Asian *asian);
int main()
{
	struct Asian asian1;
	/*struct obstruction obs1 = {1,2};*/
	
	initilizeAsian(&asian1);
	printf("%i,\n",asian1.lives);
	/*resetAsianDeltas(asian1);*/
	

return 0;
}
void initilizeAsian(struct Asian *asian)
{
	asian->x = 0;
	asian->y = 0;
	asian->lives = 3;
	asian->speed = 1;
	asian->canThrow = true;
	asian->hor_delta = 0;
	asian->hor_delta = 0;
	
	return;
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

