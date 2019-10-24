#ifndef CENG_WINDOW_H_
#define CENG_WINDOW_H_

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct window_s {
    char *name;
    int width;
    int height;
    bool quit;
    SDL_Window *sdl_win;
    SDL_Renderer *sdl_rend;
} Window;

Window *window_new(char *name, int width, int height);
void window_free(Window *self);

#endif // CENG_WINDOW_H_