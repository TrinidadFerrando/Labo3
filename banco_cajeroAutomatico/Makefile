CC = gcc-4.1
CFLAGS = -Wall -pedantic-errors -std=gnu89 -O3
HEADERS= -I./

all: clean cajero banco

cajero:
	$(CC) $(CFLAGS) -o cajero cajero.c colas.c funciones.c clave.c $(HEADERS)

banco: 
	$(CC) $(CFLAGS) -o banco banco.c colas.c funciones.c clave.c $(HEADERS)

clean:
	rm -rf *.o banco cajero



	
