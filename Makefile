binary=ceng

# no dependency
# objects
window=graphics/window
# highest level
globals=util/globals
main=main

objectfiles=$(window).o \
	$(globals).o $(main).o

all:
	# no dependency
	# objects
	gcc -c $(window).c -o $(window).o
	# highest level
	gcc -c $(globals).c -o $(globals).o
	gcc -c $(main).c -o $(main).o
	# compile
	gcc $(objectfiles) -o $(binary) -lSDL2
clean:
	rm $(objectfiles) $(binary)
