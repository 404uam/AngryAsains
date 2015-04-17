#include <osbind.h>
#include "Types.h"

void stop_sound();
void write_psg(int reg, UINT8 val);

extern volatile char *PSG_reg_select = 0xFF8800;
extern volatile char *PSG_reg_write  = 0xFF8802;

int main()
{
	long old_ssp = Super(0);

	write_psg(6,0x0F);		/* set channel A fine tune */
	write_psg(7,0x07);
	write_psg(8,0x10);			/* set channel A coarse tune */
	write_psg(9,0x10);
	write_psg(0xA,0x10);
	write_psg(0xC,0x10);	
	write_psg(0xD,0x00);	/* enable channel A & B on mixer */

	

	while (!Cconis())		/* tone now playing, await key */
		;

	stop_sound();

	Cnecin();
	Super(old_ssp);
	return 0;
}


void write_psg(int reg, UINT8 val) {
	*PSG_reg_select = reg;
	*PSG_reg_write  = val;
}

void set_tone(int channel, int tuning) {
	write_psg(channel+8,0);
}

void set_volume(int channel, int volume) {
	write_psg(channel+8,0);
}

void stop_sound() {
	write_psg(8,0);
	write_psg(9,0);
	write_psg(0xA,0);
}

/*
void set_envelope(int shape, unsigned int sustain) {
	UINT8 rough_sustain = sustain & 0x00FF;
	UINT8 fine_sustain = (sustain & 0xFF00) >> 8;

	write_psg(11,fine_sustain);
	write_psg(12,rough_sustain);
	write_psg(13,shape);
}
*/
