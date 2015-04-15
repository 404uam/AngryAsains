#include "renderer.h"
#include <osbind.h>

int main()
{
	void *base = Physbase();
	long *timer = (long *)0x462; /* address of longword auto-inc’ed 70 x per s */
	long timeNow;

	timeNow = *timer;

	

	struct Chopstick chopsticks;
	
	modelType model = {{288,0,5,1,true,0,0,{{310,50,1,1,false},{50,50,1,1,false},{0,0,1,1,false}}}, /*Asian 1*/
					   {608,288,5,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, /*Asian 2*/
					   {{40,40},{40,60},{40,80}},											  /*Obstruction 1 */
					   {{340,40},{340,60},{340,80}},										  /*Obstruction 2 */
					   {0,368}};
				
	render_frame(base);
	render_asian_facing_right(&model,base);
	render_asian_facing_left(&model,base);

	Cconin();
	
	clrBitmap32(base,model.asian1.x,model.asian1.y);
	Cconin();
	clrBitmap32(base,model.asian2.x,model.asian2.y);
	
	chopsticks = model.asian1.chopsticks[0];
	render_chopsticks_facing_right(&chopsticks,base);

	bool quit = false;


	while(quit) {
		long timeThen, timeNow, timeElapsed;
	
		timeNow = get_time();
		timeElapsed = timeNow – timeThen;

		long input;
	
		fflush (stdout);
	
		if(Cconis())
		{
			input = Cnecin();
		
			switch(input)
			{
				case UP:
						asianMoveUp(&model->asian1);			
						break;
				case DOWN: 
						asianMoveDown(&model->asian1);
						break;
				case LEFT:
						asianMoveLeft(&model->asian1);
						break;
				case RIGHT:
						asianMoveRight(&model->asian1);
						break;
				case SPACE:
						time = 1;
						break;
				case RETURN:
						printf("OUT");
						quit = true;
						break;
				default:
						break;
			
			}
		}

		if (timeElapsed > 0)
		{
			timeThen = timeNow;
		}
	}

	return 0;
}

long getTime() {
	long old_ssp;
	old_ssp = Super(0); /* enter privileged mode */
	timeNow = *timer;
	Super(old_ssp); /* exit privileged mode as soon as possible */

	return timeNow;
}