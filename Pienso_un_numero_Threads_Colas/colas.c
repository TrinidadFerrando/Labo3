#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#include "colas.h"
#include "clave.h"
#include "def.h"



int creo_id_cola_mensaje(int clave){
	int id_cola_mensajes;
	id_cola_mensajes = msgget(crear_clave(clave), 0600 | IPC_CREAT);
	if(id_cola_mensajes == -1){
		printf("Error al crear el ID de la cola de mensajes.\n");
		exit(-1);
	}
	return id_cola_mensajes;
}


int enviar_mensaje(int id_cola_mensajes, long receptor_msg, int emisor_msg, int evento_a_enviar, char *contenido_msg_a_enviar){
	mensaje msg;
	msg.tipo_msg = receptor_msg;
	msg.remitente = emisor_msg;
	msg.evento = evento_a_enviar;
	strcpy(msg.contenido_msg, contenido_msg_a_enviar);
	return msgsnd (id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.remitente) + sizeof(msg.evento) + sizeof(msg.contenido_msg), IPC_NOWAIT);
}


int recibir_mensaje(int id_cola_mensajes, long destino, mensaje *msg_a_recibir){
	mensaje msg;
	int rcv;
	rcv = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.remitente) + sizeof(msg.evento) + sizeof(msg.contenido_msg), destino, 0);
	
	msg_a_recibir->tipo_msg = msg.tipo_msg;
	msg_a_recibir->remitente = msg.remitente;
	msg_a_recibir->evento = msg.evento;
	strcpy(msg_a_recibir->contenido_msg, msg.contenido_msg);
	
	return rcv;
}


int borrar_mensaje(int id_cola_mensajes){
	mensaje msg;
	int rcv;
	do{
		rcv = msgrcv(id_cola_mensajes, (struct msgbuf *)&msg, sizeof(msg.remitente) + sizeof(msg.evento) + sizeof(msg.contenido_msg), 0, IPC_NOWAIT);
	} while(rcv>0);
	return rcv;
}


int borrar_cola_mensaje(int id_cola_mensaje){
	msgctl (id_cola_mensaje, IPC_RMID, (struct msqid_ds *)NULL);
	return 0;
}