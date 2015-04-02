#include "model.h"

int main()
{



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