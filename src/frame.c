#include "frame.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else // assuming Unix!!!
#include <unistd.h>
#endif

FrameLimiter frame_new(unsigned int fps)
{
    FrameLimiter self = (FrameLimiter){clock(), clock(), fps, 1, CLOCKS_PER_SEC / fps};
    return self;
}

void frame_waitfor(FrameLimiter *self)
{
    self->next = clock();
    self->frame_time = self->next - self->current;
    
    // don't wait if the frame took too long
    if (self->frame_time >= self->clocks_per_frame || self->frame_time < 0)
        goto Skip;

    #ifdef _WIN32
        // clks left that frame * clks / s * 1s / 1000ms
        Sleep((self->clocks_per_frame - self->frame_time) * CLOCKS_PER_SEC / 1000);
    #else // assuming Unix!!!
        // convert to milliseconds
        usleep(1000 * (self->clocks_per_frame - self->time) * CLOCKS_PER_SEC / 1000)
    #endif

Skip:
    self->current = clock();
}