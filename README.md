# C Engine
SDL2 used to create graphics in C.

# Requirements
* SDL2 must be linked
    * Linux
        * Debian-based: sudo apt-get install libsdl2-dev
    * Windows/Mac
        * https://www.libsdl.org/
        * Navigate to the downloads page and find your version
* usleep
    * The function `usleep` is used, this will work on Unix systems.
    * Windows users, check `frame_limiter.c` to adjust the `unistd.h` import for `usleep` as needed

# Building
* Build: `make`
* Binary: `ceng`
* Clean: `make clean`