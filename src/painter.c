#include "painter.h"

void painter_clear(SDL_Renderer *rend, SDL_Color c)
{
    SDL_SetRenderDrawColor(rend, c.r, c.g, c.b, c.a);
    SDL_RenderClear(rend);
}

void painter_rect(SDL_Renderer *rend, SDL_Color c, SDL_Rect rect)
{
    SDL_SetRenderDrawColor(rend, c.r, c.g, c.b, c.a);
    SDL_RenderDrawRect(rend, &rect);
}

void painter_circle(SDL_Renderer *rend, SDL_Color c, int x, int y, int r)
{
    
}
