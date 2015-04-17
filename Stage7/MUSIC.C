#include "PSG.H"
#include "MUSIC.H"

struct Note noteChA[] ={
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{E,QRTR_NOTE,VOL},
	{A,5,0},
	{E,QRTR_NOTE,VOL},
	{A,5,0},
	{E,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{F,QRTR_NOTE,VOL},
	{A,5,0},
	{E,QRTR_NOTE,VOL},
	{A,5,0},
	{E,QRTR_NOTE,VOL},
	{A,5,0},
	{E,QRTR_NOTE,VOL},
	{A,5,0},
	{B,QRTR_NOTE,VOL},
	{A,5,0},
	{A,QRTR_NOTE,VOL},
	{A,5,0}
};
struct Notes noteChB[] ={
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{G,QRTR_NOTE,VOL},
	{A,5,0},
	{B,QRTR_NOTE,VOL},
	{A,5,0},
	{B,QRTR_NOTE,VOL},
	{A,5,0},
	{B,QRTR_NOTE,VOL},
	{A,5,0},
	{B,QRTR_NOTE,VOL},
	{A,5,0},
	{B,QRTR_NOTE,VOL},
	{A,5,0},
	{B,QRTR_NOTE,VOL},
	{A,5,0},
	{C,QRTR_NOTE,VOL},
	{A,5,0},
	{C,QRTR_NOTE,VOL},
	{A,5,0},
	{C,QRTR_NOTE,VOL},
	{A,5,0},
	{A,QRTR_NOTE,0},
	{A,5,0},
	{A,QRTR_NOTE,0},
	{A,5,0}
};

 void start_music()
 {
	 long old_ssp = Super(0);
	 
	 enable_channel(0,1,1);
	 enable_channel(1,1,1);
	 
	 
 }
 
 
 void update_music(UINT32 time_elapsed)
 {
	 
	 
	 
	 
	 
 }