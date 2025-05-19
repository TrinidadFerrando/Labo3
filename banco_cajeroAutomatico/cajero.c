#include <stdio.h>            
#include <unistd.h> 
#include <string.h>       

#include "colas.h"
#include "clave.h"
#include "def.h"
#include "funciones.h"


int main(int argc, char *argv[]){

	int id_cola_mensajes;
	mensaje	msg;	

    int ncl; 
    int opcion; /*me guardo el numero del menu que me ingresen*/
    int importe;
    char buffer[100];

    msg.evento = 0;
	id_cola_mensajes = creo_id_cola_mensaje(CLAVE_BASE);

    borrar_mensaje(id_cola_mensajes);

    printf("\nCAJERO AUTOMÁTICO - BBVA\n");
    printf("\n¡Bienvenido!\n");

    printf("Por favor, ingrese su número de cliente: ");
    scanf("%d", &ncl);

/***** SOLICITUD DE INICIAR  *****/
    enviar_mensaje(id_cola_mensajes, MSG_BANCO, ncl, EVT_MENSAJE, "Iniciar sesion");
    /*enviar_mensaje(id_cola_mensajes, receptor_msg, emisor_msg, evento_a_enviar, *contenido_msg_a_enviar);*/

    while (msg.evento != EVT_FIN) {

/***** ACEPTACIÓN DE INICIAR  ****/
        recibir_mensaje(id_cola_mensajes, ncl, &msg);
        /*int recibir_mensaje(int id_cola_mensajes, long destino, mensaje *msg_a_recibir);*/
        printf(">> Cajero recibió evento: %d\n", msg.evento);
/***** ANALIZO CADA RESPUESTA(EVENTO ENVIADO) POR BANCO****/
        switch (msg.evento) {
            case EVT_MENSAJE:
                printf("\n%s\n", msg.contenido_msg);
                /*aca va aparecer el menu con las opciones */
                break;

            case EVT_RTA_SALDO:
                printf("\n%s\n", msg.contenido_msg);
                break;

            case EVT_RTA_SALDO_NOK:
                printf("\n%s\n", msg.contenido_msg);
                break;

            case EVT_RTA_DEPOSITO_OK:
                printf("\n%s\n", msg.contenido_msg);
                break;

            case EVT_RTA_DEPOSITO_NOK:
                printf("\n%s\n", msg.contenido_msg);
                break;

            case EVT_RTA_EXTRACCION_OK:
                printf("\n%s\n", msg.contenido_msg);
                break;

            case EVT_RTA_EXTRACCION_NOK:
                printf("\n%s\n", msg.contenido_msg);
                break;

            case EVT_FIN:
                break;

            default:
                printf("\nEvento no definido\n");
                break;
        }

/***** ARMADO DE MENU  *****/
        if (msg.evento != EVT_FIN){
            printf("\n  MENU BBVA \n");
            printf("1. Consultar saldo\n");
            printf("2. Depositar\n");
            printf("3. Extraer\n");
            printf("4. Salir\n");
            printf("Ingrese la opción elegida: ");
            scanf("%d", &opcion);

            switch (opcion){
                case 1:
                /*enviar_mensaje(id_cola_mensajes, receptor_msg, emisor_msg, evento_a_enviar, *contenido_msg_a_enviar);*/
                    enviar_mensaje(id_cola_mensajes, MSG_BANCO, ncl, EVT_CONSULTA_SALDO, "Consultar saldo");
                    break;
                
                case 2:
                    printf("Ingrese importe a depositar: ");
                    scanf("%d", &importe);
                    sprintf(buffer, "%d", importe);
                    enviar_mensaje(id_cola_mensajes, MSG_BANCO, ncl, EVT_DEPOSITO, buffer);
                    break;

                case 3:    
                    printf("Ingrese importe a extraer: ");
                    scanf("%d", &importe);
                    sprintf(buffer, "%d", importe);
                    enviar_mensaje(id_cola_mensajes, MSG_BANCO, ncl, EVT_EXTRACCION, buffer);
                    break;

                case 4:
                    enviar_mensaje(id_cola_mensajes, MSG_BANCO, ncl, EVT_FIN, "Salir");
                    break;

                default:
                    printf("Esa opción no existe.\n");
                    break;
            }

        }

    }
/***** FINALIZACION *****/
    if (msg.evento == EVT_FIN)
    /*enviar_mensaje(id_cola_mensajes, receptor_msg, emisor_msg, evento_a_enviar, *contenido_msg_a_enviar);*/    
    enviar_mensaje(id_cola_mensajes, MSG_BANCO, ncl, EVT_FIN, "");

    return 0;
}





