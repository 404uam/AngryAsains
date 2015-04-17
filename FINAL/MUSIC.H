 #define F 0xA02
 #define G 0x8EB
 #define E 0xA9B
 #define B 0x714
 #define C 0xD5D
 #define A 0x7F2
 
 #define VOL 11

 #define QRTR_NOTE 25
 
 #define LENGTH 39
 
 struct Note {
	 int key;
	 int duration;
	 int vol;
	 };
	 
void start_music();
void update_music(UINIT32 time_elapsed);
 