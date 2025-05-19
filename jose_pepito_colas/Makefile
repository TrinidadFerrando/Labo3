CC = gcc-4.1
CFLAGS = -Wall -pedantic-errors -std=gnu89 -O3
HEADERS= -I./

all: clean jose pepito

jose:
	$(CC) $(CFLAGS) -o jose jose.c clave.c colas.c $(HEADERS)

pepito: 
	$(CC) $(CFLAGS) -o pepito pepito.c clave.c colas.c  $(HEADERS)

clean:
	rm -rf *.o pepito jose



	
