#include <stdio.h>         
#include <stdlib.h>        
#include <unistd.h>        
#include <string.h>        

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "semaforos.h"     
#include "funciones.h"
#include "memoria.h"      
#include "def.h"           



int main(int argc, char *argv[]){

  int id_memoria;
  int id_semaforo;
  Datos *memoria = NULL; /*la estructura de los daots que cree la voy a poner en la cajita memoria*/
  int i;
  int cont;       /*creo un contador po rlas iteraciones */
    
  id_semaforo = crear_semaforo();
  memoria = (Datos*) creo_memoria(sizeof(Datos) * LARGO_CADENA , &id_memoria, CLAVE_BASE);

  cont = 0;
  while(cont < 5){
    esperar_semaforo(id_semaforo); 

    printf("Leemos la memoria %d\n", cont + 1);

    for(i = 0; i < LARGO_CADENA; i++) {
        printf("leo: %d %c\n", memoria[i].numero, memoria[i].letra);
    }

    levantar_semaforo(id_semaforo);
    usleep(500000);
  }

  liberar_memoria(memoria, id_memoria);
  return 0;
}



