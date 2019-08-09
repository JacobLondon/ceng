#include <unistd.h> // usleep
#include "frame_limiter.h"

void frame_limiter_wait(struct FrameLimiter* self)
{
    self->fps = USEC_CONVERSION / (self->target_uspf - self->actual_uspf);
    self->frame_time = 1.0 / self->fps;

    self->actual_uspf = (long)(clock() - self->frame_start);
    usleep(self->target_uspf - self->actual_uspf);
    self->frame_start = clock();
}