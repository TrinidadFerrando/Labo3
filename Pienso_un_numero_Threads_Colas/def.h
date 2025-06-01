#ifndef DEF_H
#define DEF_H

#define CLAVE_BASE 33
#define LARGO_CADENA 50

/*son mis opciones de mi 'long tipo_msg' de mi struct*/
/*tipo_msg*/
#define MSG_JUGADOR		1
#define MSG_TABLERO		2

/*identifico que tipo de evento hay.*/
/*evento*/
#define EVT_MENSAJE	1

#define EVT_NUMERO_OBJETIVO 1 /*El número que se debe adivinar*/

#define EVT_CONSULTA_NUMERO 2 
#define EVT_RTA_NOACERTO_SIGUE 3

#define EVT_RTA_ACERTO_FIN	5	/*Acertó*/

typedef struct mensaje {
  long tipo_msg;
  int remitente; /*emisor*/
  int evento;
  char contenido_msg[100];
} mensaje;