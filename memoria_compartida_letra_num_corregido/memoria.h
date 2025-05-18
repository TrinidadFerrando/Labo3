#ifndef MEMORIA_H
#define MEMORIA_H

void *creo_memoria(int size, int* id_memoria, int CLAVE_BASE);
void liberar_memoria(void *ptr, int id);

#endif


