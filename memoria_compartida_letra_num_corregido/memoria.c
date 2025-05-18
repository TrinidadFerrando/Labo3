#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#include "clave.h"
#include "memoria.h"


void *creo_memoria(int size, int* id_memoria, int CLAVE_BASE) {
    void *ptr_memoria;
    int id = shmget(crear_clave(CLAVE_BASE), size, 0777 | IPC_CREAT);
    if (id == -1) {
        printf("No consigo id para memoria compartida\n");
        exit(1);
    }

    ptr_memoria = shmat(id, NULL, 0);
    if (ptr_memoria == (void*) -1) {
        printf("No consigo memoria compartida\n");
        exit(1);
    }

    *id_memoria = id;
    return ptr_memoria;
}

void liberar_memoria(void *ptr, int id) {
    if (shmdt(ptr) == -1) {
        perror("Error al desvincular memoria compartida");
    }

    if (shmctl(id, IPC_RMID, NULL) == -1) {
        perror("Error al eliminar memoria compartida");
    }
}
