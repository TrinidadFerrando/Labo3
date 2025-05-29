#ifndef _COLA
#define _COLA

#include "def.h"

/*estructura de mi mensaje. 
IMPORTANTISIMO la presenica del 'tipo del mensaje' en tipo de dato 'long'*/
typedef struct mensaje {
  long tipo_msg;
  int remitente; /*emisor*/
  int evento;
  char contenido_msg[100];
} mensaje;

int creo_id_cola_mensaje(int clave);
int enviar_mensaje(int id_cola_mensajes, long receptor_msg, int emisor_msg, int evento_a_enviar, char *contenido_msg_a_enviar);
int recibir_mensaje(int id_cola_mensajes, long destino, mensaje *msg_a_recibir);
int borrar_mensaje(int id_cola_mensajes);
int borrar_cola_mensaje(int id_cola_mensaje);