#ifndef	RENDERER_H
#include "types.h"

void render(const struct Model *model, UINT8 *base);
void render_frame(UIN8 *base);
void render_asian(const struct Asian *asian, UINT8 *base);
void render_chopsticks(const struct Model *model, UINT8 *base);
void render_obstuction(const struct Model *model, UINT8 *base);

#endif