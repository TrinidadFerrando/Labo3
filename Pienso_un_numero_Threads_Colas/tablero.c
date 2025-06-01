#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>     

#include "global.h"     /* mutex, variables globales */
#include "thread.h"     /* funciones de hilos */
#include "funciones.h"  /*funciones del aleatorio*/
#include "colas.h"
#include "clave.h"
#include "def.h"

int main(int argc, char *argv[]) {
    
    int id_cola_mensajes;
	mensaje	msg;	

    int numero_secreto;
    int numero_recibido;
    int juego_terminado = 0;

    msg.evento = 0;
	id_cola_mensajes = creo_id_cola_mensaje(CLAVE_BASE);

    borrar_mensaje(id_cola_mensajes);

    printf("\nTABLERO DE RESULTADOS\n");
   













}