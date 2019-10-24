#include "src/ceng.h"

int main()
{
    Window *window = window_new("Ceng", 480, 640);
    Context *ctx   = context_new(window);

    context_run(ctx);

    context_free(ctx);
    window_free(window);
}
