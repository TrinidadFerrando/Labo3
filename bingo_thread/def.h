#ifndef DEF_H
#define DEF_H

/*#define CLAVE_BASE 33*/
#define LARGO_CADENA 50

#define CANT_CARTON 		5

#define BOLILLA_DESDE 		1
#define BOLILLA_HASTA 		99

#define TIEMPO_COMPRUEBA	10
#define TIEMPO_BOLILLAS		500


typedef struct tipo_jugador {
	int 	nro_jugador;	
	int 	*bolillas;						
	int  	cantidad_aciertos;
} tipo_jugador;


#endif


