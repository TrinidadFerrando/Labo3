#ifndef THREAD_H
#define THREAD_H

typedef struct {
    int id_jugador;
    int numero_aleatorio;
    int *alguien_acerto;
    int intentos;
} datos_jugador;

void *funcion_thread(void *datos);

#endif







