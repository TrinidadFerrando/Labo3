CC = gcc-4.1
CFLAGS = -Wall -pedantic-errors -std=gnu89 -O3 -pthread
HEADERS= -I./

all: clean pienso_numero

pienso_numero:
	$(CC) $(CFLAGS) -o pienso_numero pienso_numero.c thread.c funciones.c global.c $(HEADERS)

clean:
	rm -rf *.o pienso_numero



	
