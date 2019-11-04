#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else // assuming Unix!!!
#include <unistd.h>
#endif

#include "frame.h"

FrameLimiter *frame_new(unsigned int fps)
{
    FrameLimiter *self = malloc(sizeof(FrameLimiter));
    self->current      = clock();
    self->next         = clock();
    self->fps          = fps;
    self->frame_time   = 1;
    self->clocks_per_frame = CLOCKS_PER_SEC / fps;

    return self;
}

void frame_waitfor(FrameLimiter *self)
{
    self->next = clock();
    self->frame_time = self->next - self->current;

    // don't wait if the frame took too long
    if (self->frame_time >= self->clocks_per_frame || self->frame_time < 0)
        goto Skip;

    clock_t difference = self->clocks_per_frame - self->frame_time;

    #ifdef _WIN32
        // clks left that frame * clks / s * 1s / 1000ms
        Sleep(difference * CLOCKS_PER_SEC / 1000);
    #else // assuming Unix!!!
        // already in microseconds
        usleep(difference);
    #endif

Skip:
    self->current = clock();
}
