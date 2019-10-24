#include <stdlib.h>

#include "context.h"
#include "painter.h"

Event event_new(bool *req, event_fn action)
{
    Event self = (Event){req, action};
    return self;
}

Context *context_new(Window *window)
{
    Context *self = malloc(sizeof(Context));
    self->window  = window;
    self->events  = array_new(sizeof(event_fn), NULL);
    self->mouse.x = 0;
    self->mouse.y = 0;
    self->bgc     = BLACK;

    return self;
}

void context_free(Context *self)
{
    if (!self)
        return;
    
    array_free(self->events);
    free(self);
}

void context_run(Context *self)
{
    while (!self->window->quit) {
        painter_clear(self->window->sdl_rend, self->bgc);

        context_poll(self);
        context_draw(self);
        context_update(self);
    }
}

void context_draw(Context *self)
{
    Event *e = (Event *)self->events->data;

    for (size_t i = 0; i < self->events->end; i++) {
        if (e->req)
            e->action();
    }
}

void context_poll(Context *self)
{
    SDL_Event e;
    SDL_GetMouseState(&self->mouse.x, &self->mouse.y);

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            self->window->quit = true;
            break;
        default:
            break;
        }
    }
}

void context_update(Context *self)
{
    SDL_RenderPresent(self->window->sdl_rend);
}
