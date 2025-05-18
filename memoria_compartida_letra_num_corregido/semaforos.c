#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#include "semaforos.h"
#include "clave.h"



int crear_semaforo(){
    key_t id_clave = crear_clave();
    int id_semaforo = semget(id_clave, 1, 0600 | IPC_CREAT);
    if (id_semaforo == -1){
        printf("ERROR: No se pudo crear el semaforo.\n");
        exit(1);
    }
    return id_semaforo;
}

void iniciar_semaforo(int id_semaforo, int valor_inicial){
    semctl(id_semaforo, 0, SETVAL, valor_inicial);
}

void esperar_semaforo(int id_semaforo){
    struct sembuf operacion;
    operacion.sem_num = 0;
    operacion.sem_op = -1;
    operacion.sem_flg = 0;
    semop(id_semaforo, &operacion, 1);
}

void levantar_semaforo(int id_semaforo){
    struct sembuf operacion;
    operacion.sem_num = 0;
    operacion.sem_op = 1;
    operacion.sem_flg = 0;
    semop(id_semaforo, &operacion, 1);
}


