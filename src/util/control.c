#include "control.h"

#include "../globals.h"    // interface

void control_setup()
{
    interface_append_event(&interface, SDLK_UP, control_forward);
    interface_append_event(&interface, SDLK_LEFT, control_left);
    interface_append_event(&interface, SDLK_RIGHT, control_right);
}

void control_forward()
{
    for (int i = 0; i < interface.objects_len; i++) {
        interface.objects[i].z++;
        object_transform(&interface.objects[i]);
    }
}

void control_left()
{
    for (int i = 0; i < interface.objects_len; i++) {
        interface.objects[i].x++;
        object_transform(&interface.objects[i]);
    }
}

void control_right()
{
    for (int i = 0; i < interface.objects_len; i++) {
        interface.objects[i].x--;
        object_transform(&interface.objects[i]);
    }
}
