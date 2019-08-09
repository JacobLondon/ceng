#include <stdio.h>

#include "color.h"
#include "frame_limiter.h"
#include "interface.h"
#include "mouse.h"
#include "../util/globals.h"

void interface_construct(struct Interface* self, const char* title, int width, int height, double fps)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
        perror("Error: 'interface_construct' SDL Window failed to initialize.\n");

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        perror("Error: 'interface_construct' SDL Renderer failed to initialize.\n");

    self->width = width;
    self->height = height;
    self->background = WHITE;
    self->mouse = (struct Mouse){0, 0};
    self->loop = true;
    self->fps = fps;
}

void interface_destruct(struct Interface* self)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void interface_run(struct Interface* self)
{
    struct FrameLimiter frame_limiter = FRAME_LIMITER_INIT(self->fps);
    
    while (self->loop) {
        interface_clear(self);
        handle_input(self);
        handle_graphics(self);
        interface_update(self);
        frame_limiter_wait(&frame_limiter);
    }
}

void handle_input(struct Interface* self)
{
    SDL_Event e;

    SDL_GetMouseState(&self->mouse.x, &self->mouse.y);

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            self->loop = false;
            break;
        }
    }
}

void handle_graphics(struct Interface* self)
{
    interface_setcol(self, BLUE);
    SDL_Rect r = {self->mouse.x - 50, self->mouse.y - 50, 100, 100};
    SDL_RenderFillRect(renderer, &r);
}

void interface_clear(struct Interface* self)
{
    interface_setcol(self, self->background);
    SDL_RenderClear(renderer);
}

void interface_update(struct Interface* self)
{
    SDL_RenderPresent(renderer);
}

void interface_setcol(struct Interface* self, Color c)
{
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
}
