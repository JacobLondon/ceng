#include <stdio.h>

#include "color.h"
#include "interface.h"
#include "mouse.h"
#include "globals.h"

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
    for (int i = 0; i < INTERFACE_SDL_KEYS; self->keys[i++] = false);
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
        interface_input_read(self);
        interface_input_exec(self);
        interface_graphics(self);
        interface_update(self);
        frame_limiter_wait(&self->frame_limiter);
    }
}

void interface_input_read(struct Interface* self)
{
    SDL_Event e;

    SDL_GetMouseState(&self->mouse.x, &self->mouse.y);

    // read all events
    while (SDL_PollEvent(&e)) {
        switch(e.type) {
        case SDL_QUIT:
            self->loop = false;
            break;
        case SDL_KEYDOWN:
            if (e.key.keysym.sym < INTERFACE_SDL_KEYS)
                self->keys[e.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            if (e.key.keysym.sym < INTERFACE_SDL_KEYS)
                self->keys[e.key.keysym.sym] = false;
            break;
        default:
            break;
        }
    }
}

void interface_input_exec(struct Interface* self)
{
    // traverse loaded events
    for (int i = 0; i < self->events_len; i++) {
        // the current event's key is 'true'
        if (self->keys[self->events[i].key])
            self->events[i].action();
    }
}

void interface_graphics(struct Interface* self)
{
    int i;
    for (i = 0; i < self->objects_len; i++) {
        self->objects[i].draw(&self->objects[i]);
    }

    for (i = 0; i < self->draw_funcs_len; i++) {
        (self->draw_funcs[i])();
    }
}

void interface_append_draw_func(struct Interface* self, void (* func))
{
    if (self->draw_funcs_len < INTERFACE_MAX_DRAW_FUNCS)
        self->draw_funcs[self->draw_funcs_len++] = func;
    else {
        printf("Error: 'interface_append_draw_func' index exceeds maximum draw functions.\n");
        exit(-1);
    }
}

void interface_append_event(struct Interface* self, int key, void (* action)())
{
    struct Event event = EVENT_INIT(key, action);

    if (self->events_len < INTERFACE_MAX_EVENTS)
        self->events[self->events_len++] = event;
    else {
        printf("Error: 'interface_append_event' index exceeds maximum events.\n");
        exit(-1);
    }
}

void interface_append_object(struct Interface* self, struct Object object)
{
    if (self->objects_len < INTERFACE_MAX_OBECTS)
        self->objects[self->objects_len++] = object;
    else {
        printf("Error: 'interface_append_object' index exceeds maximum events.\n");
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
