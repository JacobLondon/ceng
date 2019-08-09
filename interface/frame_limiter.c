#include <unistd.h> // usleep
#include "frame_limiter.h"

void frame_limiter_wait(struct FrameLimiter* self)
{
    // record the frame per second and the time (seconds) per frame
    self->fps = USEC_CONVERSION / (self->target_uspf - self->actual_uspf);
    self->frame_time = 1.0 / self->fps;

    // actual microseconds per frame since the timestamp
    self->actual_uspf = (long)(clock() - self->timestamp);
    // sleep until the target time has been reached
    usleep(self->target_uspf - self->actual_uspf);
    // create a timestamp
    self->timestamp = clock();
}