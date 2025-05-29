#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "thread.h"
#include "funciones.h"
#include "global.h"


void *funcion_thread(void *datos) {
    datos_jugador *p_jugador = (datos_jugador *)datos;
    int numero_aleatorio = p_jugador->numero_aleatorio; /*número que debe adivinarse*/
    int intentos; /*guarda el número generado aleatoriamente en cada intento*/
    int acerto = 0;                                     /*bandera para indicar si se ha acertado el número*/
    int usados[/*99*/ 20] = {0};      /*array local al hilo que guarda que números ya fueron intentados por ese jugador*/
    int esperar;                                        /*variable para guardar el tiempo de espera entre intentos*/    

    while (!acerto) {
        pthread_mutex_lock(&mutex);
        if (*(p_jugador->alguien_acerto)) {
            pthread_mutex_unlock(&mutex);
            break; 
        }
        intentos = num_aleatorio(1, /*99*/ 20);
        
        /*condicion para numeros no repetidos*/
        while (usados[intentos - 1]) { 
            intentos = num_aleatorio(1, /*99*/ 20); 
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








