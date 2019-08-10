#include "draw.h"

#include "../util/globals.h" // access to global interface

/**
 * Define drawing functions here.
 */

void draw_cursor()
{
    interface_draw_color(&interface, BLUE);
    SDL_Rect r = {interface.mouse.x - 50, interface.mouse.y - 50, 100, 100};
    SDL_RenderFillRect(renderer, &r);
}

