CC=gcc
CFLAGS=-I.

main: test.o src/cog.o
		$(CC) -o test test.o src/cog.o

clean: 
		rm -f test.o src/cog.o test
