#ifndef CENG_PAINTER_H_
#define CENG_PAINTER_H_

#include <SDL2/SDL.h>

#include "color.h"

void painter_clear(SDL_Renderer *rend, SDL_Color c);
void painter_rect(SDL_Renderer *rend, SDL_Color c, SDL_Rect rect);
void painter_circle(SDL_Renderer *rend, SDL_Color c, int x, int y, int r);

#endif // CENG_PAINTER_H_