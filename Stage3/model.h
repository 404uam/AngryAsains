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

struct Chopstick{
	unsigned int x,y;
	int direction;
	int speed;
};

struct PlayerInfo{
	unsigned int x,y;
};

void resetAsianDeltas(struct Asian *asian);
void asainMoveRight(struct Asian *asian);
void asianMoveLeft(struct Asian *asian);
void asianMoveUp(struct Asian *asian);
void asianMoveDown(struct Asian *asian);
void asianMoveModel(struct Asian *asian);

void chopstickMove(struct Chopstick *chopstick);

#endif
