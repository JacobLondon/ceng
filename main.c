#include "src/ceng.h"
#undef main

#include <stdio.h>

static void grid()
{
    
}

int main(int argc, char** argv)
{
    Window *window = window_new("Ceng", 640, 480);
    Context *ctx   = context_new(window);

    // setup
    Event ge = event_new(true, grid);
    array_append(ctx->events, &ge);

    context_run(ctx);

    context_free(ctx);
    window_free(window);

    return 0;
}
