#include "demo.h"

Context *ctx;
Window *window;

void keys();
bool call_keys = true;
void draw();
bool call_draw = true;

unsigned cast();
void setup();

void setup()
{
    event_insert(ctx, keys, call_keys);
    event_insert(ctx, draw, call_draw)
}

void cast()
{
    window = window_new("Cast", 640, 480);
    ctx    = context_new(window, 60);

    setup();
    context_run();

    context_free(ctx);
    window_free(window);
}
