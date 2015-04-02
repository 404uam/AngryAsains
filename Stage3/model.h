#ifndef	MODEL_H
#define RASTER_H
#define bool int
#define true 1
#define false -1

struct Asian{
	unsigned int x,y,lives;
	int speed;
	bool canThrow;
	int hor_delta;
	int ver_delta;
};

struct Obstruction{
	unsigned int x,y;
};

struct Chopsticks{
	unsigned int x,y;
	int speed;
};

struct PlayerInfo{
	unsigned int x,y;
};

void resetAsianDeltas(struct Asian *asian);
void asainMoveRight(struct Asian *asain);
#endif
