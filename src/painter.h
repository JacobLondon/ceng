#ifndef CENG_PAINTER_H_
#define CENG_PAINTER_H_

#include <SDL2/SDL.h>

#include "color.h"

void painter_color(SDL_Renderer *rend, Color c);
void painter_clear(SDL_Renderer *rend, Color c);
void painter_rect(SDL_Renderer *rend, Color c, int x, int y, int w, int h);
void painter_circle(SDL_Renderer *rend, Color c, int x, int y, int r);

#endif // CENG_PAINTER_H_