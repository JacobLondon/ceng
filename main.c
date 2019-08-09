#include "util/globals.h"
#include "interface/interface.h"

int main(int argc, char** argv)
{
    // initialize global interface and SDL window/renderer
    interface_construct(&interface, "Title", 1080, 720, 60);
    // poll SDL events and draw frames
    interface_run(&interface);
    interface_destruct(&interface);
}