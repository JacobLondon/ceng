#ifndef CENG_CONTEXT_H_
#define CENG_CONTEXT_H_

#include "array.h"
#include "color.h"
#include "frame.h"
#include "window.h"

typedef void (* event_fn)(void);

typedef struct event_s {
    bool *req;
    event_fn action;
} Event;

Event *event_new(bool *req, event_fn action);
#define event_insert(Context, Function, BoolCondition) \
    array_push(Context->events, event_new(&(BoolCondition), Function))

typedef struct context_s {
    FrameLimiter *frame_l;
    Window *window;
    Array *events;

    struct mouse_s {
        int x, y;
    } mouse;

    unsigned char *keystate;

    SDL_Color back;
} Context;

Context *context_new(Window *window, unsigned int fps);
void context_free(Context *self);
void context_run(Context *self);
void context_update(Context *self);
void context_poll(Context *self);


#endif // CENG_CONTEXT_H_
