#include <osbind.h>
#include "Types.h"

void stop_sound();
void write_select();

extern volatile char *PSG_reg_select = 0xFF8800;
extern volatile char *PSG_reg_write  = 0xFF8802;

int main()
{
	long old_ssp = Super(0);

	*PSG_reg_select = 0;		/* set channel A fine tune = 248 */
	*PSG_reg_write  = 478;

	*PSG_reg_select = 1;		/* set channel A coarse tune = 0 */
	*PSG_reg_write  = 0;

	*PSG_reg_select = 7;		/* enable channel A on mixer */
	*PSG_reg_write  = 0x3E;

	*PSG_reg_select = 8;		/* set channel A volume = 11 */
	*PSG_reg_write  = 11;

	while (!Cconis())		/* tone now playing, await key */
		;

	stop_sound();

	Cnecin();
	Super(old_ssp);
	return 0;
}


void stop_sound() {
	write_select(8,0);
	write_select(9,0);
	write_select(10,0);
}

void write_select(int select, int write) {
	*PSG_reg_select = select;
	*PSG_reg_write  = write;
}

void envelope(int shape, unsigned int sustain) {
	UINT8 rough_sustain = sustain & 0x00FF;
	UINT8 fine_sustain = (sustain & 0xFF00) >> 8;

	write_select(11,fine_sustain);
	write_select(12,rough_sustain);
	write_select(13,shape);
}
