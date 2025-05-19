#ifndef _COLA
#define _COLA

#include "def.h" /*depende del orden de inclusión de los headers para funcionar entonces le sumo esto para evitar posibles errores */

/*estructura de mi mensaje. 
IMPORTANTISIMO la presenica del 'tipo del mensaje' en tipo de dato 'long'*/
typedef struct mensaje {
  long tipo_msg;
  int remitente;
  int evento;
  char contenido_msg[100];
} mensaje;

int creo_id_cola_mensaje(int clave);
int enviar_mensaje(int id_cola_mensajes, long tipo_msg_a_enviar, int remitente_a_enviar, int evento_a_enviar, char *contenido_msg_a_enviar);
int recibir_mensaje(int id_cola_mensajes, long tipo_msg_a_recibir, mensaje *msg_a_recibir);
int borrar_mensaje(int id_cola_mensajes);
int borrar_cola_mensaje(int id_cola_mensaje);



#endif

/* OJO LAS LLAMADAS DE MENSAJES SON EVENTOS BLOQUEANTES */






