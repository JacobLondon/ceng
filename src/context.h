#ifndef CENG_CONTEXT_H_
#define CENG_CONTEXT_H_

typedef struct context_s {
    
} Context;

Context *context_new();

#define EVENT_COUNT 64

typedef struct event_s {
    int key;
    void (* action[EVENT_COUNT])(void);
} Event;

void context_run(Context *self);
void context_draw(Context *self);
void context_poll(Context *self);
void context_update(Context *self);
void context_color(Context *self, Color c);

#endif // CENG_CONTEXT_H_
