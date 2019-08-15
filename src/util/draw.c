#include "draw.h"

#include "../globals.h" // interface


void draw_setup()
{
    interface_append_draw_func(&interface, draw_cursor);
}

/**
 * Define drawing functions here.
 */

void draw_cursor()
{
    interface_draw_color(&interface, BLUE);
    SDL_Rect r = {interface.mouse.x - 50, interface.mouse.y - 50, 100, 100};
    SDL_RenderFillRect(renderer, &r);
}

