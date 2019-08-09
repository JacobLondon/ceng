#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "color.h"

typedef struct Window {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    struct Color background;
    bool loop;
} Window;

void window_construct(struct Window* self, const char* title, int width, int height);
void window_destruct(struct Window* self);
void window_run(struct Window* self);
void handle_input(struct Window* self);

void window_clear(struct Window* self);
void window_update(struct Window* self);
void window_setcol(struct Window* self, Color c);

#endif // WINDOW_H