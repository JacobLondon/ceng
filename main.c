#include "util/globals.h"
#include "interface/interface.h"

int main(int argc, char** argv)
{
    interface_construct(&interface, "CENG", 1080, 720, 60);
    interface_run(&interface);
    interface_destruct(&interface);
}