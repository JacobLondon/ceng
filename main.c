#include "util/globals.h"
#include "graphics/draw.h"

void setup();

int main(int argc, char** argv)
{
    setup();
    
    interface_construct(&interface, "CENG", 1080, 720, 60);
    interface_run(&interface);
    interface_destruct(&interface);
}

void setup()
{
    draw_function_append(&interface, draw_cursor);
}
