#include "model.h"


int main()
{

	/*struct Asian asian2 = {639,399,5,1,true,1,-1};*/
	/*struct Chopstick chopsticks[3] = {{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}};*/
	/*struct Asian asian1 = {0,0,5,1,true,1,-1,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}};*/
	/*struct Obstruction obs1[3] = {{40,40},{40,60},{40,80}};*/
	/*struct Obstruction obs2[3] = {{340,40},{340,60},{340,80}};*/
	/*struct PlayerInfo pi = {0,368};*/
	
	modelType model = {{0,0,5,1,true,1,-1,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, /*Asian 1*/
					   {0,0,5,1,true,1,-1,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, /*Asian 2*/
					   {{40,40},{40,60},{40,80}},											  /*Obstruction 1 */
					   {{340,40},{340,60},{340,80}},										  /*Obstruction 2 */
					   {0,368}};															  /*PlayerInfo Box*/
	
	printf("%i,\n",model.asian1.hor_delta);
	printf("%i,\n",model.asian1.ver_delta);
	/*resetAsianDeltas(&asian1);*/
	/*printf("%i,\n",asian2.hor_delta);*/
/* 	printf("%i,\n",asian2.ver_delta);*/	
	printf("%i,%i,\n",model.obs1[1].y,model.obs2[1].x);

	return 0;
}