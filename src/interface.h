#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "color.h"
#include "event.h"
#include "frame_limiter.h"
#include "mouse.h"
#include "util/object.h"

#define INTERFACE_MAX_DRAW_FUNCS 32
#define INTERFACE_MAX_EVENTS 64
#define INTERFACE_SDL_KEYS 322
#define INTERFACE_MAX_OBECTS 64

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
    int events_len;
    // keys pressed
    bool keys[INTERFACE_SDL_KEYS];
    // array to hold function pointers which draw graphics
    funcp draw_funcs[INTERFACE_MAX_DRAW_FUNCS];
    int draw_funcs_len;
    // all of the objects to draw on screen
    struct Object objects[INTERFACE_MAX_OBECTS];
    int objects_len;
} Interface;

#define INTERFACE_INIT { \
    .background = WHITE, \
    .mouse = (struct Mouse){0, 0}, \
    .loop = true, \
    .events_len = 0, \
    .draw_funcs_len = 0, \
    .objects_len = 0, \
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
 * \brief Poll and record SDL events.
 */
void interface_input_read(struct Interface* self);
/**
 * \brief Execute registered events.
 */
void interface_input_exec(struct Interface* self);
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
 * \brief Insert an Event with a SDL key and a function for it to trigger
 */
void interface_append_event(struct Interface* self, int key, void (*)());
/**
 * \brief Insert an Object
 */
void interface_append_object(struct Interface* self, struct Object object);
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