#include <unistd.h> // usleep
#include "frame_limiter.h"

void frame_limiter_wait(struct FrameLimiter* self)
{
    // record the frame per second and the time (seconds) per frame
    self->usleft = self->target_uspf - self->actual_uspf;
    self->fps = USEC_CONVERSION / (self->usleft);
    self->frame_time = 1.0 / self->fps;

    // actual microseconds per frame since the timestamp
    self->actual_uspf = (long)(clock() - self->timestamp);
    // sleep until the target time has been reached, or go as fast as possible
    if (self->usleft > 0)
        usleep(self->usleft);
    // create a timestamp
    self->timestamp = clock();
}