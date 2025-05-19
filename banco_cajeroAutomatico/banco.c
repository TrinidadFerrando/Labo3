#include <stdio.h>            
#include <unistd.h> 
#include <string.h>     
#include <stdlib.h>  

#include "colas.h"
#include "clave.h"
#include "def.h"
#include "funciones.h"


int main(int argc, char *argv[]){

	int id_cola_mensajes;
	mensaje	msg;	

    cliente cli[CANT_CLIENTES];

    int i;
    int var_saldo;
    char var_contenido_msg[100];
    int movimento_dinero;

    msg.evento = 0;
	id_cola_mensajes = creo_id_cola_mensaje(CLAVE_BASE);

    iniciar_aleatorio();

    printf("\nSISTEMA BANCARIO\n");

/***** CARGAR INFO DEL CLIENTE *****/
    for (i=0; i<CANT_CLIENTES; i++) {
        cli[i].nro_cliente = i;
        cli[i].saldo = num_aleatorio(0,100000);
    }
    
    while (msg.evento != EVT_FIN) {   

/***** RECEPCION DE SOLICITUD PARA INICIAR *****/
        /*int recibir_mensaje(int id_cola_mensajes, long destino, mensaje *msg_a_recibir);*/   
        recibir_mensaje(id_cola_mensajes, MSG_BANCO, &msg);/*solicitud del cliente para ingresar = "iniciar sesion"*/

/***** GENERACIÓN DE RESPUESTAS(EVENTOS RECIBIDOS) POR EL CAJERO****/       
        switch (msg.evento) {
            case EVT_MENSAJE:
                printf("El cliente %d inició sesión\n", msg.remitente);
                /*enviar_mensaje(id_cola_mensajes, receptor_msg, emisor_msg, evento_a_enviar, *contenido_msg_a_enviar);*/
                enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_MENSAJE, "Bienvenido! Ingrese la operación que desea realizar: ");
                break;

            case EVT_CONSULTA_SALDO:
                printf("El cliente %d quiere conocer su saldo\n", msg.remitente);
                var_saldo = consultar_saldo(cli, msg.remitente);

                if (var_saldo != -1) {
                    sprintf(var_contenido_msg, "Su Saldo es de: $%d", var_saldo);
                    enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_RTA_SALDO, var_contenido_msg);
                } else {
                    printf("Error con la consulta de saldo del cliente %d \n", msg.remitente);
                    enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_RTA_SALDO_NOK, "Error con la consulta de saldo del cliente");
                }
                break;

            case EVT_DEPOSITO:
                printf("El cliente %d quiere depositar %s\n", msg.remitente, msg.contenido_msg);
                movimento_dinero = atoi(msg.contenido_msg);
                var_saldo = depositar(cli, msg.remitente, movimento_dinero);

                if (var_saldo != -1) {
                    sprintf(var_contenido_msg, "Operación exitosa. Su saldo actual es de $%d ", var_saldo);
                    enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_RTA_DEPOSITO_OK, var_contenido_msg);
                } else {
                    printf("Error al depositar con el cliente %d \n", msg.remitente);
                    enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_RTA_DEPOSITO_NOK, "Error al depositar con el cliente");
                }
                break;

                case EVT_EXTRACCION:
                    printf("El cliente %d quiere extraer %s\n", msg.remitente, msg.contenido_msg);
                    movimento_dinero = atoi(msg.contenido_msg);
                    var_saldo = extraer(cli, msg.remitente, movimento_dinero);

                    if (var_saldo != -1) {
                        sprintf(var_contenido_msg, "Operación exitosa. Su saldo actual es de $%d ", var_saldo);
                        enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_RTA_EXTRACCION_OK, var_contenido_msg);
                    } else {
                        printf("Error al extraer con el cliente %d\n", msg.remitente);
                        enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_RTA_EXTRACCION_NOK, "Error al extraer dinero con el cliente");
                    }
                    break;

                case EVT_FIN:
                    printf("El cliente %d termino la operación.\n", msg.remitente);
                    enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_FIN, "");
                    break;
                
                default:
                    printf("\nEvento no definido\n");
                    break;

        }
    
    
    }
/***** FINALIZACION *****/
    if (msg.evento == EVT_FIN)
        enviar_mensaje(id_cola_mensajes, msg.remitente, MSG_BANCO, EVT_FIN, "");

    return 0;     
}





