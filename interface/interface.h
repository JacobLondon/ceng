#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "color.h"
#include "mouse.h"

typedef struct Interface {
    int width;
    int height;
    struct Color background;
    struct Mouse mouse;
    bool loop;
    double fps;
} Interface;

#define INTERFACE_INIT {}

void interface_construct(struct Interface* self, const char* title, int width, int height, double fps);
void interface_destruct(struct Interface* self);
void interface_run(struct Interface* self);
void handle_input(struct Interface* self);

void interface_clear(struct Interface* self);
void interface_update(struct Interface* self);
void interface_setcol(struct Interface* self, Color c);

#endif // INTERFACE_H