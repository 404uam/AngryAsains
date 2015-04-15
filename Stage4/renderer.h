#ifndef	RENDERER_H
#include "model.h"
#include "types.h"
#include "raster.h"

void render(const struct Model *model, UINT8 *base);
void render_frame(UINT8 *base);
void render_asian_facing_right(const struct Asian *asian, UINT32 *base);
void render_asian_facing_left(const struct Asian *asian, UINT32 *base);
void render_chopsticks_facing_right(const struct Chopsticks *chopsticks, UINT8 *base);
void render_chopsticks_facing_left(const struct Chopsticks *chopsticks, UINT8 *base);
void render_obstuction(const struct Model *model, UINT8 *base);

#endif