#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "color.h"
#include "event.h"
#include "frame_limiter.h"
#include "mouse.h"

#define INTERFACE_MAX_DRAW_FUNCS 32
#define INTERFACE_MAX_EVENTS 64

/**
 * \brief Interface with the global SDL_Window/Renderer
 */
typedef void (* funcp)();
typedef struct Interface {
    // user initializer

    // screen width and height
    int width, height;
    // target fps initializer
    struct FrameLimiter frame_limiter;

    // auto initializer
    
    // screen background color
    struct Color background;
    // mouse coordinates
    struct Mouse mouse;
    // program loop boolean
    bool loop;
    // hold all of the events
    struct Event events[INTERFACE_MAX_EVENTS];
    // array to hold function pointers which draw graphics
    funcp draw_funcs[INTERFACE_MAX_DRAW_FUNCS];
    // draw_funcs current append index
    int draw_func_index;
} Interface;

#define INTERFACE_INIT { \
    .background = WHITE, \
    .mouse = (struct Mouse){0, 0}, \
    .loop = true, \
    .draw_func_index = 0, \
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
void interface_input(struct Interface* self);
/**
 * \brief Draw graphics each frame.
 */
void interface_graphics(struct Interface* self);
/**
 * \brief Insert a function which will draw each frame.
 * \param func A void function with no args to be called in order.
 */
void interface_append_draw_func(struct Interface* self, void (* func));
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
void interface_draw_color(struct Interface* self, Color c);

#endif // INTERFACE_H