#ifndef DEF_H
#define DEF_H

#define CLAVE_BASE 33
#define LARGO_CADENA 50

/*identifico quien manda el mensaje: Banco=1, Cajero=2*/
/*son mis opciones de mi 'long tipo_msg' de mi struct*/
/*tipo_msg*/
#define MSG_BANCO 		1
#define MSG_CAJERO		2

/*identifico que tipo de evento es: 1=mensaje, 2=fin_del_proceso*/
/*evento*/
#define EVT_MENSAJE	1

#define EVT_CONSULTA_SALDO 2
#define EVT_RTA_SALDO 22
#define EVT_RTA_SALDO_NOK 23

#define EVT_DEPOSITO 3
#define EVT_RTA_DEPOSITO_OK 31
#define EVT_RTA_DEPOSITO_NOK 32

#define EVT_EXTRACCION 4
#define EVT_RTA_EXTRACCION_OK 41
#define EVT_RTA_EXTRACCION_NOK 42

#define EVT_FIN	5		

/*cantidad solicitada*/
#define CANT_CLIENTES 100


typedef struct cliente {
    int nro_cliente;
    int saldo;
} cliente ;

#endif


