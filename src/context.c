#include <stdlib.h>

#include "context.h"
#include "painter.h"
#include "frame.h"

Event event_new(bool *req, event_fn action)
{
    Event self = (Event){req, action};
    return self;
}

Context *context_new(Window *window)
{
    Context *self  = malloc(sizeof(Context));
    self->window   = window;
    self->events   = array_new(sizeof(event_fn), NULL);
    self->mouse.x  = 0;
    self->mouse.y  = 0;
    SDL_PumpEvents();
    self->keystate = SDL_GetKeyboardState(NULL);
    self->back     = DARK;

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
    FrameLimiter fl = frame_new(60);

    while (!self->window->quit) {
        painter_clear(self->window->rend, self->back);

        context_poll(self);
        context_update(self);
        SDL_RenderPresent(self->window->rend);

        frame_waitfor(&fl);
    }
}

void context_update(Context *self)
{
    Event *e = (Event *)self->events->data;

    for (size_t i = 0; i < self->events->end; i++) {
        if (e[i].req)
            e[i].action();
    }
}

void context_poll(Context *self)
{
    SDL_GetMouseState(&self->mouse.x, &self->mouse.y);
    SDL_PumpEvents();
    self->keystate = SDL_GetKeyboardState(NULL);

    SDL_Event e;

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
