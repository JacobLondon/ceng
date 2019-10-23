#include <stdlib.h> // malloc, free
#include <stdio.h>

#include "window.h"

Window *window_new(char *name, int width, int height)
{
    Window *self = malloc(sizeof(Window));
    self->name = name;
    self->width = width;
    self->height = height;
    self->mouse.x = 0;
    self->mouse.y = 0;
    self->quit = false;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    self->sdl_win = SDL_CreateWindow(
        name,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        self->width,
        self->height,
        SDL_WINDOW_SHOWN
    );
    if (!self->sdl_win) {
        fprintf(stderr, "Error: failed to initialize SDL Window\n");
        exit(-1);
    }
    self->sdl_rend = SDL_CreateRenderer(self->sdl_win, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Error: failed to initialize SDL Renderer\n");
        exit(-1);
    }

    return self;
}

void window_free(Window *self)
{
    if (!self)
        return;

    if (self->sdl_win)
        SDL_DestroyWindow(self->sdl_win);
    
    if (self->sdl_rend)
        SDL_DestroyRenderer(self->sdl_rend);

    SDL_Quit();

    free(self);
}
