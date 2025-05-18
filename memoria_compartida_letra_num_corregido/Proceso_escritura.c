#include <stdio.h>         
#include <stdlib.h>        
#include <unistd.h>        
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "semaforos.h"
#include "funciones.h"    
#include "memoria.h"      
#include "def.h"  


int main(int argc, char *argv[]){
    int id_memoria;
    int id_semaforo;
    Datos *memoria = NULL;  /*la estructura de los daots que cree la voy a poner en la cajita memoria*/
    int i;
    int num_var;
    char letra_var;
    int cont;       /*creo un contador por las iteraciones */


    id_semaforo = crear_semaforo();
    iniciar_semaforo(id_semaforo, 1);

    memoria = (Datos*) creo_memoria(sizeof(Datos) * LARGO_CADENA , &id_memoria, CLAVE_BASE);
    iniciar_aleatorio();

    cont = 0;
    while(cont < 5){
        esperar_semaforo(id_semaforo); 

        printf("Escribimos la memoria %d\n", cont + 1);

        for(i=0; i<LARGO_CADENA ; i++){
            num_var = num_aleatorio(1,10);
            letra_var = letra_aleatorio('A', 'Z');

            memoria[i].numero = num_var ;
            memoria[i].letra = letra_var ;
            printf("Escribí: %d %c\n", memoria[i].numero, memoria[i].letra);
        }
        levantar_semaforo(id_semaforo);
        usleep(500000);
    }
    liberar_memoria(memoria, id_memoria);
    return 0;
}

