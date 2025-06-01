#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>     

#include "global.h"     /* mutex, variables globales */
#include "thread.h"     /* funciones de hilos */
#include "funciones.h"  /*funciones del aleatorio*/

int main(int argc, char *argv[]) {
    int cant_jugadores = 1;
    int numero_aleatorio;
    int alguien_acerto = 0;
    int i;
    
    pthread_t *p_hilos;
    datos_jugador *p_datos;
    pthread_attr_t 	atributos;

    if (argc > 1) {
        cant_jugadores = atoi(argv[1]);
        if (cant_jugadores < 1) {
            printf("El numero de jugadores debe ser al menos 1.\n");
            return 1;
        }         
    }

    iniciar_aleatorio();

    numero_aleatorio = num_aleatorio(1, 20/*99*/);
    printf("El número que los jugadores tienen que acertar es el: %d\n", numero_aleatorio);

    
    p_hilos = (pthread_t *)malloc(sizeof(pthread_t) * cant_jugadores);
    p_datos = (datos_jugador *)malloc(sizeof(datos_jugador) * cant_jugadores);


    pthread_attr_init(&atributos);
    pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < cant_jugadores; i++) {
        p_datos[i].id_jugador = i + 1;
        p_datos[i].numero_aleatorio = numero_aleatorio;
        p_datos[i].alguien_acerto = &alguien_acerto;
        p_datos[i].intentos = 0;
        pthread_create(&p_hilos[i], &atributos, funcion_thread, (void *)&p_datos[i]);
    }

    /* Aca entiendo que 'falta' mi while con la condicion de trabajo. PERO:
        El while no es necesario en este caso, ya que los hilos se ejecutan de forma independiente y el hilo principal
        no necesita esperar a que un jugador acierte el número para continuar.
     */


    for (i = 0; i < cant_jugadores; i++) {
        pthread_join(p_hilos[i], NULL);
        printf("Jugador %d terminó con %d intentos\n", p_datos[i].id_jugador, p_datos[i].intentos);
    }
    free(p_hilos);
    free(p_datos);
    pthread_mutex_destroy(&mutex);

    printf("Fin del juego.\n");
    return 0;

}







