#include "frame.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else // assuming Unix!!!
#include <unistd.h>
#endif

FrameLimiter frame_new(unsigned int fps)
{
    FrameLimiter self = (FrameLimiter){clock(), clock(), fps, 1};
    return self;
}

void frame_waitfor(FrameLimiter *self)
{
    clock_t clocks_per_frame = CLOCKS_PER_SEC / self->fps;
    // TODO: Finish correct conversion
    self->next = clock() / CLOCKS_PER_SEC;

    self->time = self->next - self->current;
    printf("Time: %d\n", self->next - self->current);
    printf("Duration: %d\n", self->time);

    if (self->time > 1000)
        return;

    #ifdef _WIN32
        Sleep(self->time);
    #else // assuming Unix!!!
        usleep(self->time * 1000)
    #endif

    self->current = clock() / CLOCKS_PER_SEC;
}
