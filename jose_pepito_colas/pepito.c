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

    printf("\n*** SOY DON PEPITO ***\n");

    while(msg.evento != EVT_FIN){
/*int recibir_mensaje(int id_cola_mensajes,       long tipo_msg_a_recibir             , mensaje *msg_a_recibir);*/
/*                                              a quien va digiido el mensaje                                */
        recibir_mensaje(id_cola_mensajes, MSG_PEPITO, &msg);
		printf("Destino   %d\n", (int) msg.tipo_msg);
		printf("Remitente %d\n", msg.remitente);
		printf("Evento    %d\n", msg.evento);
		printf("Mensaje   %s\n", msg.contenido_msg);
        
        switch (msg.evento){
            case EVT_MENSAJE:
                /*printf("Recibi un mensaje\n");*/
				/*printf("Mensaje   %s\n", msg.char_mensaje);*/
				usleep(500000);/*por qué uso aca esto y no un usleep?*/
				
                if(strcmp(msg.contenido_msg, "HOLA DON PEPITO")==0)
                    enviar_mensaje(id_cola_mensajes, MSG_JOSE, MSG_PEPITO, EVT_MENSAJE, "HOLA DON JOSE");
                else if(strcmp(msg.contenido_msg, "PASO USTED POR CASA")==0)
					enviar_mensaje(id_cola_mensajes, MSG_JOSE, MSG_PEPITO, EVT_MENSAJE, "POR SU CASA YO PASE");
				else if(strcmp(msg.contenido_msg, "VIO USTED A MI ABUELA")==0)
					enviar_mensaje(id_cola_mensajes, MSG_JOSE, MSG_PEPITO, EVT_MENSAJE, "A SU ABUELA YO LA VI");
                break;

			case EVT_FIN:
				/*if(strcmp(msg.contenido_msg, "ADIOS DON PEPITO")==0)*/
                enviar_mensaje(id_cola_mensajes , MSG_JOSE, MSG_PEPITO, EVT_FIN, "ADIOS DON JOSE");
				printf("Recibi el final.\n");
			break;

			default:
				printf("\nEvento no definido!!\n");
			break;
        }

    }
    if(msg.evento != EVT_FIN)	
	    enviar_mensaje(id_cola_mensajes, MSG_JOSE, MSG_PEPITO, EVT_FIN, "");		
/*enviar_mensaje(int id_cola_mensajes, long tipo_msg_a_enviar, int remitente_a_enviar, int evento_a_enviar, char *contenido_msg_a_enviar);*/
	return 0;

}





