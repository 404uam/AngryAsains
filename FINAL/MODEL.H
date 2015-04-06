#ifndef MODEL_H
#define MODEL_H

#include "types.h"

#define RASTER_H
#define bool int
#define true 1
#define false -1

struct Chopstick {
	UINT16 x,y;
	int direction;
	int speed;
	bool isThrown;
};

struct Asian {
	UINT16 x,y,lives;
	int speed;
	bool canThrow;
	int hor_delta;
	int ver_delta;
	struct Chopstick chopsticks[3];
};

struct Obstruction {
	UINT16 x,y;
};

struct PlayerInfo {
	UINT16 x,y;
};

struct Model {
	struct Asian asian1;
	struct Asian asian2;
	struct Obstruction obs1[3];
	struct Obstruction obs2[3];
	struct PlayerInfo pi;
};

typedef struct Model modelType;

void resetAsianDeltas(struct Asian *asian);
void asianMoveRight(struct Asian *asian);
void asianMoveLeft(struct Asian *asian);
void asianMoveUp(struct Asian *asian);
void asianMoveDown(struct Asian *asian);
void asianMoveModel(struct Asian *asian);
void asianThrowChopstick(struct Asian *asian);

void spawnChopstick(struct Chopstick *chopstick, struct Asian *asian);
void chopstickMove(struct Chopstick *chopstick);


#endif