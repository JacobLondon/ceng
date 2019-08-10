binary=ceng
compiler=gcc

# no dependency
# objects
frame_limiter=interface/frame_limiter
interface=interface/interface
# highest level
globals=util/globals
draw_functions=graphics/draw
main=main

objectfiles=$(interface).o $(frame_limiter).o \
	$(globals).o $(draw_functions).o $(main).o

all:
	# objects
	$(compiler) -c $(interface).c -o $(interface).o
	$(compiler) -c $(frame_limiter).c -o $(frame_limiter).o
	# highest level
	$(compiler) -c $(globals).c -o $(globals).o
	$(compiler) -c $(draw_functions).c -o $(draw_functions).o
	$(compiler) -c $(main).c -o $(main).o
	# compile
	$(compiler) $(objectfiles) -o $(binary) -lSDL2
clean:
	rm $(objectfiles) $(binary)
