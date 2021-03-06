#ifndef	PSG_H
#include "types.h"

void write_psg(int reg, UINT8 val);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();

#endif
