#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "pthread.h"

#include "def.h"
#include "global.h"
#include "funciones.h"



void *ThreadJugadores (void *parametro){
	int g_carton_lleno = 0;
	int g_control = 0;
	int cantidad_aciertos=0;
	int carton[CANT_CARTON]={0};/*creo array*/
	int *bolillas;
	int nro_jugador;
	int encontrado=0;
	int done=0;
	int bolilla=0;
	int	i, j;

	tipo_jugador *datos_thread 	= (tipo_jugador*) parametro;
	nro_jugador = datos_thread->nro_jugador;
	bolillas = datos_thread->bolillas;


	iniciar_aleatorio();

	
	printf("\nSoy el jugador %d\n", nro_jugador+1);

	for(i=0; i<CANT_CARTON; i++){
		encontrado=0;
		while(encontrado==0){
			bolilla = num_aleatorio(BOLILLA_DESDE, BOLILLA_HASTA);
			encontrado = 1;
			for(j=0; j<CANT_CARTON; j++){
				if(bolilla == carton[j])
					encontrado=0;	
			}
		}
		carton[i]=bolilla; 
	}
	

		
	while(done==0)
	{
		pthread_mutex_lock (&mutex);
			if(g_control!=0){
				g_control--;				
				if(g_carton_lleno==0){			
					for(i=0; i<CANT_CARTON; i++){	
						if(carton[i]!=0){
							for(j=0; j<BOLILLA_HASTA; j++){			
								if(carton[i]==bolillas[j] && carton[i]!=0){	
									carton[i]=0;
									cantidad_aciertos++;
								}
							}
						}
					}
					printf("JUGADOR %d ", nro_jugador+1);				
					for(j=0; j<CANT_CARTON; j++){			
						printf(" %02d ", carton[j]);
					}
					if(cantidad_aciertos==CANT_CARTON){
						g_carton_lleno=nro_jugador+1;
					}
					printf(" Aciertos=%d g_control=%d g_carton_lleno=%d\n", cantidad_aciertos, g_control, g_carton_lleno);				
				}
				else{
					done=1;
				}
			}
		pthread_mutex_unlock (&mutex);

		usleep(TIEMPO_COMPRUEBA*1000);		

	};

	datos_thread->cantidad_aciertos=cantidad_aciertos;
	pthread_exit ((void *)"Listo");
}
