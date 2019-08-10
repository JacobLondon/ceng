binary=ceng

# no dependency
# objects
frame_limiter=interface/frame_limiter
interface=interface/interface
# highest level
globals=util/globals
draw_functions=graphics/draw_functions
main=main

objectfiles=$(interface).o $(frame_limiter).o \
	$(globals).o $(draw_functions).o $(main).o

all:
	# objects
	gcc -c $(interface).c -o $(interface).o
	gcc -c $(frame_limiter).c -o $(frame_limiter).o
	# highest level
	gcc -c $(globals).c -o $(globals).o
	gcc -c $(draw_functions).c -o $(draw_functions).o
	gcc -c $(main).c -o $(main).o
	# compile
	gcc $(objectfiles) -o $(binary) -lSDL2
clean:
	rm $(objectfiles) $(binary)
