#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();
	
	clrScrn(base);
	Cconin();
	plot_pixel(base,100,100);
	plot_pixel(base,320,150);

	plot_ver_line(base,320,380,48);
	Cconin();
	clrScrn(base);
	plot_pixel(base,100,100);
	plot_pixel(base,120,120);
	paintRgn(base,100,100,5,10);
	

	return 0;
}
