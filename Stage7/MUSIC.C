#include "PSG.H"
#include "MUSIC.H"

int currentIndex;
int currentDuration;
int currentTime;

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
	 
	 currentIndex = 0;
	 currentDuration = 0;
	 currentTime = 0;
	 
	 set_tone(0,noteChA[currentIndex].key);
	 set_volume(0,noteChA[currentIndex].vol);
	 set_tone(0,noteChB[currentIndex].key);
	 set_volume(0,noteChB[currentIndex].vol);
	 
	 currentIndex++;
	 
	 Super(old_ssp);
	 
 }
 
 
 void update_music(UINT32 time_elapsed)
 {
	 if(currentTime > noteChA[currentDuration].duration){
		 currentIndex++;
		 /*enable_channel(0,1,1);
		 enable_channel(1,1,1);*/
		 set_tone(0,noteChA[currentIndex].key);
		 set_volume(0,noteChA[currentIndex].vol);
		 set_tone(0,noteChB[currentIndex].key);
		 set_volume(0,noteChB[currentIndex].vol);
		 currentTime = 0;
	 }
	 else{
		 currentTime++;
	 }
	 
	 if(currentTime == LENGTH)
	 {
		 currentIndex = 0;
		 currentTime = 0;
	 }
	 
	 
	 
	 
 }