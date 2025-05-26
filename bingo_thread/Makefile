CC = gcc-4.1
CFLAGS = -Wall -pedantic-errors -std=gnu89 -O3 -pthread
HEADERS= -I./

all: clean bingo

bingo:
	$(CC) $(CFLAGS) -o bingo bingo.c threads.c funciones.c global.c $(HEADERS)

clean:
	rm -rf *.o bingo



	
