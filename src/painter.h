#ifndef CENG_PAINTER_H_
#define CENG_PAINTER_H_

#include <SDL2/SDL.h>

#include "color.h"

void painter_clear(SDL_Renderer *rend, SDL_Color c);
void painter_rect(SDL_Renderer *rend, SDL_Color c, SDL_Rect rect);
void painter_rect_fill(SDL_Renderer *rend, SDL_Color c, SDL_Rect rect);
void painter_circle(SDL_Renderer *rend, SDL_Color c, int x, int y, int radius);
void painter_circle_fill(SDL_Renderer *rend, SDL_Color c, int x, int y, int radius);
void painter_line(SDL_Renderer *rend, SDL_Color c, int x1, int y1, int x2, int y2);

#endif // CENG_PAINTER_H_