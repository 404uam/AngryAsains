#include "psg.h"
#include <osbind.h>

int main()
{
	long old_ssp = Super(0);

	write_psg(6,0x0F);	
	write_psg(7,0x07);
	write_psg(8,0x10);			
	write_psg(9,0x10);
	write_psg(0xA,0x10);
	write_psg(0xC,0x10);	
	write_psg(0xD,0x00);	

	while (!Cconis())
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
	UINT8 fine_tone = tuning & 0x0FF;
	UINT8 rough_tone = (tuning & 0xF00) >> 8;

	if(channel == 0) {
		write_psg(0,fine_tone);
		write_psg(1,rough_tone);
	} else if(channel == 1) {
		write_psg(2,fine_tone);
		write_psg(3,rough_tone);
	} else {
		write_psg(4,fine_tone);
		write_psg(5,rough_tone);
	}
}

void set_volume(int channel, int volume) {
	write_psg(channel+8,volume);
}

void enable_channel(int channel, int tone_on, int noise_on) {
	if(channel == 0) {
		if(tone_on == 1 && noise_on == 1) {
			write_psg(7,0x36);
		} else if(tone_on == 0 && noise_on == 1) {
			write_psg(7,0x37);
		} else
			write_psg(7,0x3E);
		}
	} else if(channel == 1) {
		if(tone_on == 1 && noise_on == 1) {
			write_psg(7,0x2D);
		} else if(tone_on == 0 && noise_on == 1) {
			write_psg(7,0x2F);
		} else
			write_psg(7,0x3D);
		}
	} else {
		if(tone_on == 1 && noise_on == 1) {
			write_psg(7,0x1B);
		} else if(tone_on == 0 && noise_on == 1) {
			write_psg(7,0x1F);
		} else
			write_psg(7,0x3B);
		}
	}
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