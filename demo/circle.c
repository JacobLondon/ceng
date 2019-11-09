#include <stdio.h>

#include "demo.h"

/**
 * Globals
 */

static Context *ctx;
static Window *window;

// custom globals
static bool call_keys = true;
static bool call_draw = true;

/**
 * Event functions
 */

static void keys()
{
    if (ctx->keystate[SDL_SCANCODE_ESCAPE]) {
        printf("Exiting...\n");
        ctx->window->quit = true;
    }
    else if (ctx->keystate[SDL_SCANCODE_SPACE])
        call_draw = false;
    else if (ctx->keystate[SDL_SCANCODE_LSHIFT])
        call_draw = true;

}

static void draw()
{
    //painter_rect(window->rend, RED, (SDL_Rect){ctx->mouse.x-50, ctx->mouse.y-50, 100, 100});
    //painter_rect_fill(window->rend, RED, (SDL_Rect){ctx->mouse.x-50, ctx->mouse.y-50, 100, 100});
    painter_circle_fill(window->rend, RED, ctx->mouse.x, ctx->mouse.y, 100);
}

/**
 * Initialization
 */

static void setup()
{
    Event *keys_event = event_new(&call_keys, keys);
    array_push(ctx->events, keys_event);
    Event *draw_event = event_new(&call_draw, draw);
    array_push(ctx->events, draw_event);
}

void circle()
{
    window = window_new("Ceng", 640, 480);
    ctx    = context_new(window, 60);

    setup();

    context_run(ctx);

    // tear down
    context_free(ctx);
    window_free(window);
}
