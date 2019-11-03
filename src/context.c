#include <stdlib.h>

#include "context.h"
#include "painter.h"
#include "frame.h"

Event *event_new(bool *req, event_fn action)
{
    Event *self = malloc(sizeof(Event));
    self->req = req;
    self->action = action;
    return self;
}

Context *context_new(Window *window, unsigned int fps)
{
    Context *self  = malloc(sizeof(Context));
    self->frame_l  = frame_new(fps);
    self->window   = window;
    self->events   = array_new(free);
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
    free(self->frame_l);
    free(self);
}

void context_run(Context *self)
{
    while (!self->window->quit) {
        painter_clear(self->window->rend, self->back);

        context_poll(self);
        context_update(self);
        SDL_RenderPresent(self->window->rend);

        frame_waitfor(self->frame_l);
    }
}

void context_update(Context *self)
{
    Event **e = (Event **)self->events->buf;

    for (size_t i = 0; i < self->events->end; i++) {
        if (*(e[i]->req) == true)
            e[i]->action();
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
