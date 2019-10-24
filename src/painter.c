#include "painter.h"

void painter_color(SDL_Renderer *rend, Color c)
{
    SDL_SetRenderDrawColor(rend, c.r, c.g, c.b, c.a);
}

void painter_clear(SDL_Renderer *rend, Color c)
{
    SDL_SetRenderDrawColor(rend, c.r, c.g, c.b, c.a);
    SDL_RenderClear(rend);
}

void painter_rect(SDL_Renderer *rend, Color c, int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_SetRenderDrawColor(rend, c.r, c.g, c.b, c.a);
    SDL_RenderDrawRect(rend, &rect);
}

void painter_circle(SDL_Renderer *rend, Color c, int x, int y, int r)
{
    
}
