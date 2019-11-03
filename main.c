#include <stdio.h>

#include "src/ceng.h"

/**
 * Globals
 */

static Context *ctx;
static Window *window;

// custom globals
static bool call_loop = true;

/**
 * Event functions
 */

static void loop()
{
    //painter_rect(window->rend, RED, (SDL_Rect){ctx->mouse.x-50, ctx->mouse.y-50, 100, 100});
    //painter_rect_fill(window->rend, RED, (SDL_Rect){ctx->mouse.x-50, ctx->mouse.y-50, 100, 100});
    painter_circle_fill(window->rend, RED, ctx->mouse.x, ctx->mouse.y, 100);

    if (ctx->keystate[SDL_SCANCODE_ESCAPE]) {
        printf("Exiting...\n");
        ctx->window->quit = true;
    }

}

/**
 * Initialization
 */

static void setup()
{
    Event loop_event = event_new(&call_loop, loop);
    array_push(ctx->events, &loop_event);
}

int main()
{
    window = window_new("Ceng", 640, 480);
    ctx    = context_new(window);

    setup();

    context_run(ctx);

    // tear down
    context_free(ctx);
    window_free(window);

    return 0;
}
