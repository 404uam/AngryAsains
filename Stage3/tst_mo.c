#include "events.h"
#include <stdio.h>
#include <osbind.h>

int main()
{
	/*time = 0;*/
	bool stop = false;
	
	modelType model = {{0,0,5,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, /*Asian 1*/
					   {608,0,5,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, /*Asian 2*/
					   {{40,40},{40,60},{40,80}},											  /*Obstruction 1 */
					   {{340,40},{340,60},{340,80}},										  /*Obstruction 2 */
					   {0,368}};															  /*PlayerInfo Box*/
	
	while(stop == false)
	{
		keyPress(&model, &stop);

		if(time)
		{
			clock_tick(&model);
		}	
	
	}
	
	/*resetAsianDeltas(&asian1);*/
	/*printf("%i,\n",asian2.hor_delta);*/
	/* 	printf("%i,\n",asian2.ver_delta);*/	
	/*printf("%i,%i,\n",model.obs1[1].y,model.obs2[1].x);*/

	return 0;
}