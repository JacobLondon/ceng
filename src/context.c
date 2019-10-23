#include "context.h"

void context_run(Context *self)
{

}

void context_draw(Context *self)
{

}

void context_poll(Context *self)
{
    SDL_Event e;
    SDL_GetMouseState(&self->mouse.x, &self->mouse.y);

    while (SDL_PollEvent(&e) {
        switch (e.type) {
        case SDL_QUIT:
            self->quit = true;
            break;
        default:
            break;
        }
    }
}

void context_update(Context *self)
{
    SDL_RenderPresent(self->sdl_rend);
}

void context_color(Context *self, Color c)
{
    SDL_SetRenderDrawColor(self->sdl_rend, c.r, c.g, c.b, c.a);
}

