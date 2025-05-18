CC = gcc-4.1
CFLAGS = -Wall -pedantic-errors -std=gnu89 -O3
HEADERS= -I./

all: clean Proceso_escritura Proceso_lectura

Proceso_escritura:
	$(CC) $(CFLAGS) -o Proceso_escritura Proceso_escritura.c memoria.c funciones.c semaforos.c clave.c  $(HEADERS)

Proceso_lectura: 
	$(CC) $(CFLAGS) -o Proceso_lectura Proceso_lectura.c memoria.c funciones.c semaforos.c clave.c  $(HEADERS)

clean:
	rm -rf *.o Proceso_lectura Proceso_escritura



	
