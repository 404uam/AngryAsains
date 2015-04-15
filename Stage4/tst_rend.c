#include "renderer.h"
#include <osbind.h>

int main()
{
	void *base = Physbase();
	
	struct Chopstick chopsticks;
	
	modelType model = {{0,0,5,1,true,0,0,{{310,50,1,1,false},{50,50,1,1,false},{0,0,1,1,false}}}, /*Asian 1*/
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



return 0;
}
