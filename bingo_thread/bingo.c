#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

#include "def.h"
#include "global.h"
#include "funciones.h"
#include "thread.h"


int main(int argc, char *argv[]){
	int cant_hilos=1; /*declaro la cantidad de hilos que voy a tener*/
	pthread_t *id_hilo;
	pthread_attr_t 	atributos;
	tipo_jugador *datos_thread;
	int i, j;
	int bolillas[BOLILLA_HASTA] = {0};
  	int bolilla = 0;

	int done = 0;
  	int encontrado;
	
	/*Si se pasa un argumento por consola, se toma como cantidad de jugadores*/
	if (argc>1)
		cant_hilos = atoi(argv[1]);

	printf("%d\n", cant_hilos);
	
	/*inicio el generador de numeros aleatorios*/
	iniciar_aleatorio();

	/*Guardo en mi Ram los id de los hilos que use*/
	id_hilo = (pthread_t*)malloc(sizeof(pthread_t)*cant_hilos);

	
	pthread_attr_init (&atributos);
	pthread_attr_setdetachstate (&atributos, PTHREAD_CREATE_JOINABLE);

	pthread_mutex_init (&mutex, NULL);

	datos_thread = (tipo_jugador*) malloc(sizeof(tipo_jugador)*cant_hilos);

	for(i=0; i<cant_hilos; i++){
		datos_thread[i].nro_jugador = i;
		datos_thread[i].cantidad_aciertos=0;
		datos_thread[i].bolillas = bolillas;
		pthread_create (&id_hilo[i], &atributos, ThreadJugadores, &datos_thread[i]);
	}
		
	while(done==0){
		pthread_mutex_lock (&mutex);
			if(g_control == 0){
				g_control = cant_hilos; 				
				if(g_carton_lleno==0){			
					encontrado=0;
					while(encontrado==0){
						bolilla = num_aleatorio(BOLILLA_DESDE, BOLILLA_HASTA);
						encontrado = 1;
						for(j=0; j<BOLILLA_HASTA; j++){
							if(bolilla == bolillas[j])
								encontrado=0;	
						}
					}
					bolillas[i++]=bolilla; 
					
					printf("BINGO: bolilla = %d\n", bolilla);	
				}
				else{
					done = 1;
				}
			}
		pthread_mutex_unlock (&mutex);
		usleep(TIEMPO_BOLILLAS*1000);	
	};

	for(i=0; i<cant_hilos; i++){
		pthread_join (id_hilo[i], NULL);
		printf("TERMINO\n");
		printf("PPAL: Jugador %d: %d aciertos\n", i+1, datos_thread[i].cantidad_aciertos);
	}			
	return 0;

}





