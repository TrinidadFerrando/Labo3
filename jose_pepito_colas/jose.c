#include <stdio.h>            
#include <unistd.h>  
#include <string.h>

#include "colas.h"
#include "clave.h"
#include "def.h"


int main(int argc, char *argv[]){

	int id_cola_mensajes;
	mensaje	msg;	
	msg.evento = 0;
	id_cola_mensajes = creo_id_cola_mensaje(CLAVE_BASE);

	borrar_mensaje(id_cola_mensajes);

    printf("\n*** SOY DON JOSE ***\n");
                                        /*jose envia mensaje a pepito */
	enviar_mensaje(id_cola_mensajes , MSG_PEPITO, MSG_JOSE, EVT_MENSAJE, "HOLA DON PEPITO");
/*enviar_mensaje(int id_cola_mensajes, long tipo_msg_a_enviar, int remitente_a_enviar, int evento_a_enviar, char *contenido_msg_a_enviar) */
/*                                             a                         de                                  */
    while(msg.evento != EVT_FIN){
/*int recibir_mensaje(int id_cola_mensajes, long tipo_msg_a_recibir, mensaje *msg_a_recibir);*/
        recibir_mensaje(id_cola_mensajes, MSG_JOSE, &msg);
		printf("Destino   %d\n", (int) msg.tipo_msg);
		printf("Remitente %d\n", msg.remitente);
		printf("Evento    %d\n", msg.evento);
		printf("Mensaje   %s\n", msg.contenido_msg);
		switch (msg.evento){
            case EVT_MENSAJE:
                /*printf("Recibi un mensaje\n");*/
				/*printf("Mensaje   %s\n", msg.char_mensaje);*/
				usleep(500000);/*por qué uso aca esto y no un usleep?*/
				
                if(strcmp(msg.contenido_msg, "HOLA DON JOSE")==0)
                    enviar_mensaje(id_cola_mensajes, MSG_PEPITO, MSG_JOSE, EVT_MENSAJE, "PASO USTED POR CASA");
				else if(strcmp(msg.contenido_msg, "POR SU CASA YO PASE")==0)
					enviar_mensaje(id_cola_mensajes, MSG_PEPITO, MSG_JOSE, EVT_MENSAJE, "VIO USTED A MI ABUELA");
				else if(strcmp(msg.contenido_msg, "A SU ABUELA YO LA VI")==0)
					enviar_mensaje(id_cola_mensajes, MSG_PEPITO, MSG_JOSE, EVT_FIN, "ADIOS DON PEPITO");
            break;

			case EVT_FIN:
				printf("Recibi el final.\n");
			break;

			default:
				printf("\nEvento no definido!!\n");
			break;
                }


    }

	if(msg.evento != EVT_FIN)	
		enviar_mensaje(id_cola_mensajes, MSG_PEPITO, MSG_JOSE, EVT_FIN, "");		
/*enviar_mensaje(int id_cola_mensajes, long tipo_msg_a_enviar, int remitente_a_enviar, int evento_a_enviar, char *contenido_msg_a_enviar);*/
	return 0;



}




