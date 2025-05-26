#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "thread.h"
#include "funciones.h"
#include "global.h"


void *funcion_thread(void *datos) {
    datos_jugador *p_jugador = (datos_jugador *)datos;
    int numero_aleatorio = p_jugador->numero_aleatorio;
    int intentos;
    int acerto = 0;
    int usados[99] = {0};  /*los numeros ya usados*/
    int esperar;

    while (!acerto) {
        pthread_mutex_lock(&mutex);
        if (*(p_jugador->alguien_acerto)) {
            pthread_mutex_unlock(&mutex);
            break; 
        }
        intentos = num_aleatorio(1, 99);
        
        /*condicion para numeros no repetidos*/
        while (usados[intentos - 1]) { 
            intentos = num_aleatorio(1, 99); 
        }
        usados[intentos - 1] = 1;
        p_jugador->intentos++;

        printf("Jugador %d intenta con el número: %d\n", p_jugador->id_jugador, intentos);

        if (intentos == numero_aleatorio) {
            *(p_jugador->alguien_acerto) = p_jugador->id_jugador; 
            acerto = 1;
            printf("Jugador %d acertó el número!\n", p_jugador->id_jugador);
        }
        pthread_mutex_unlock(&mutex);
        esperar = num_aleatorio(500, 5000); 
        usleep(esperar * 1000); 
    }
    return NULL;
}








