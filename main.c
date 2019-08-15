#include "src/ceng.h"

int main(int argc, char** argv)
{
    object_setup();
    draw_setup();
    control_setup();
    
    interface_construct(&interface, "CENG", 1080, 720, 60);
    interface_run(&interface);
    interface_destruct(&interface);
}
