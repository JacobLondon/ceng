#include "window.h"
#include "color.h"

void window_construct(struct Window* self, const char* title, int width, int height)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    self->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!self->window)
        perror("Error: 'window_construct' SDL Window failed to initialize.\n");

    self->renderer = SDL_CreateRenderer(self->window, -1, 0);
    if (!self->renderer)
        perror("Error: 'window_construct' SDL Renderer failed to initialize.\n");

    self->width = width;
    self->height = height;
    self->background = (Color){WHITE};
    self->loop = true;
}

void window_destruct(struct Window* self)
{
    SDL_DestroyWindow(self->window);
    SDL_DestroyRenderer(self->renderer);
    SDL_Quit();
}

void window_run(struct Window* self)
{
    while (self->loop) {
        window_clear(self);
        handle_input(self);
        window_update(self);
    }
}

void handle_input(struct Window* self)
{
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            self->loop = false;
            break;
        }
    }
}

void window_clear(struct Window* self)
{
    window_setcol(self, self->background);
}

void window_update(struct Window* self)
{
    SDL_RenderPresent(self->renderer);
}

void window_setcol(struct Window* self, Color c)
{
    SDL_SetRenderDrawColor(self->renderer, c.r, c.g, c.b, c.a);
}
