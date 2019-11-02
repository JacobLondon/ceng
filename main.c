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
    
}

/**
 * Initialization
 */

static void setup()
{
    Event ge = event_new(&call_loop, loop);
    array_append(ctx->events, &ge);
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
