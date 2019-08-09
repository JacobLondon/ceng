#include <stdio.h>
#include <SDL2/SDL.h>

#include "util/globals.h"
#include "graphics/window.h"

int main(int argc, char** argv)
{
    window_construct(&window, "Title", 1080, 720);
    window_run(&window);
    window_destruct(&window);
}