#include "util/globals.h"
#include "graphics/draw_functions.h"

int main(int argc, char** argv)
{
    draw_function_append(&interface, draw_cursor);
    interface_construct(&interface, "CENG", 1080, 720, 60);
    interface_run(&interface);
    interface_destruct(&interface);
}