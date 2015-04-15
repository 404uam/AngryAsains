#include "renderer.h"
#include <osbind.h>

int main()
{
	void *base = Physbase();
	
	modelType model = {{0,0,5,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, /*Asian 1*/
					   {608,0,5,1,true,0,0,{{0,0,1,1,false},{0,0,1,1,false},{0,0,1,1,false}}}, /*Asian 2*/
					   {{40,40},{40,60},{40,80}},											  /*Obstruction 1 */
					   {{340,40},{340,60},{340,80}},										  /*Obstruction 2 */
					   {0,368}};
					   
					   
	render_frame(base);




return 0;
}
