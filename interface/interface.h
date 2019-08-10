#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "color.h"
#include "mouse.h"

#define INTERFACE_MAX_DRAW_FUNCS 32

/**
 * \brief Interface with the global SDL_Window/Renderer
 */
typedef void (* funcp)();
typedef struct Interface {
    int width;
    int height;
    struct Color background;
    struct Mouse mouse;
    bool loop;
    double fps;
    funcp draw_funcs[INTERFACE_MAX_DRAW_FUNCS];
    int func_index;
} Interface;

#define INTERFACE_INIT { \
    .func_index = 0, \
}

/**
 * \brief Initialize global interface and SDL window/renderer.
 */
void interface_construct(struct Interface* self, const char* title, int width, int height, double fps);
/**
 * \brief Delete and remove all SDL entities used.
 */
void interface_destruct(struct Interface* self);
/**
 * \brief Poll SDL events and draw frames.
 */
void interface_run(struct Interface* self);
/**
 * \brief Poll SDL events.
 */
void handle_input(struct Interface* self);
/**
 * \brief Draw graphics each frame.
 */
void handle_graphics(struct Interface* self);
/**
 * \brief Insert a function which will draw each frame.
 */
void draw_function_append(struct Interface* self, void (* func));
/**
 * \brief Clear the interface to its default background color.
 */
void interface_clear(struct Interface* self);
/**
 * \brief Render all objects onto the screen.
 */
void interface_update(struct Interface* self);
/**
 * \brief Set the global renderer's drawing color.
 */
void interface_setcol(struct Interface* self, Color c);

#endif // INTERFACE_H