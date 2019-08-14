#include "src/globals.h"
#include "src/draw.h"

void setup();
void test();

int main(int argc, char** argv)
{
    setup();
    
    interface_construct(&interface, "CENG", 1080, 720, 60);
    interface_run(&interface);
    interface_destruct(&interface);
}

void setup()
{
    interface_append_draw_func(&interface, draw_cursor);
    interface_append_event(&interface, SDLK_SPACE, test);
}

void test()
{
    printf("test\n");
}