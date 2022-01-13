all: clean link

link: build
	gcc -Wall -std=c99 cesar.o test_cesar.o -o cesar

build: cesar.h cesar.c test_cesar.c
	gcc -Wall -std=c99 -c cesar.c
	gcc -Wall -std=c99 -c test_cesar.c

clean:
	rm -f *.o
	rm -f cesar

start: link
	./cesar $(entree) $(sortie) 

test: link
	bats test.bats
