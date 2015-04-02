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
	int x;
	int y;
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
void asianMoveLeft(struct Asian *asian);
void asianMoveUp(struct Asian *asian);
void asianMoveDown(struct Asian *asian);
void asianMoveModel(struct Asian *asian);

#endif
