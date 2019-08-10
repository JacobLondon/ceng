#include <stdio.h>

#include "color.h"
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

    // initializer
    self->width = width;
    self->height = height;
    self->frame_limiter = FRAME_LIMITER_INIT(fps);
}

void interface_destruct(struct Interface* self)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void interface_run(struct Interface* self)
{
    while (self->loop) {
        interface_clear(self);
        interface_input(self);
        interface_graphics(self);
        interface_update(self);
        frame_limiter_wait(&self->frame_limiter);
    }
}

void interface_input(struct Interface* self)
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

void interface_graphics(struct Interface* self)
{
    for (int i = 0; i < self->draw_func_index; i++) {
        (self->draw_funcs[i])();
    }
}

void interface_append_draw_func(struct Interface* self, void (* func))
{
    if (self->draw_func_index + 1 < INTERFACE_MAX_DRAW_FUNCS)
        self->draw_funcs[self->draw_func_index++] = func;
    else {
        printf("Error: 'draw_function_append' index exceeds maximum draw functions.\n");
        exit(-1);
    }
}

void interface_clear(struct Interface* self)
{
    interface_draw_color(self, self->background);
    SDL_RenderClear(renderer);
}

void interface_update(struct Interface* self)
{
    SDL_RenderPresent(renderer);
}

void interface_draw_color(struct Interface* self, Color c)
{
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
}
