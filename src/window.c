#include <stdlib.h> // malloc, free
#include <stdio.h>

#include "window.h"

Window *window_new(char *name, int width, int height)
{
    Window *self = malloc(sizeof(Window));
    self->name = name;
    self->width = width;
    self->height = height;
    self->quit = false;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    self->win = SDL_CreateWindow(
        name,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        self->width,
        self->height,
        SDL_WINDOW_SHOWN
    );
    if (!self->win) {
        fprintf(stderr, "Error: failed to initialize SDL Window\n");
        exit(-1);
    }
    self->rend = SDL_CreateRenderer(self->win, -1, 0);
    if (!self->rend) {
        fprintf(stderr, "Error: failed to initialize SDL Renderer\n");
        exit(-1);
    }

    return self;
}

void window_free(Window *self)
{
    if (!self)
        return;

    if (self->win)
        SDL_DestroyWindow(self->win);
    
    if (self->rend)
        SDL_DestroyRenderer(self->rend);

    SDL_Quit();

    free(self);
}
