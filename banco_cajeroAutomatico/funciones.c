#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "funciones.h"


int i;

void iniciar_aleatorio(){
	srand(time(0));
}

int num_aleatorio(int desde, int hasta){
    return rand() % (hasta-desde+1) + desde;
}

int consultar_saldo(cliente cli[], int nro_cliente){
    for (i=0; i<CANT_CLIENTES; i++) {
        if (cli[i].nro_cliente == nro_cliente) {
            return cli[i].saldo;
        }
    }
    return -1;
}

int depositar(cliente cli[], int nro_cliente, int monto){
    for (i=0; i<CANT_CLIENTES; i++) {
        if (cli[i].nro_cliente == nro_cliente) {
            cli[i].saldo += monto;
            return cli[i].saldo;
        }
    }
    return -1;
}

int extraer(cliente cli[], int nro_cliente, int monto){
    for (i=0; i<CANT_CLIENTES; i++) {
        if (cli[i].nro_cliente == nro_cliente) {
        if (monto > 0 && cli[i].saldo >= monto && cli[i].saldo > 0) {
            cli[i].saldo -= monto;
        }else{
            return -1;
        }
        return cli[i].saldo;
        }
    }
    return -1;
}


