#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "def.h" /*depende del orden de inclusión de los headers para funcionar entonces le sumo esto para evitar posibles errores */

void iniciar_aleatorio();
int num_aleatorio(int desde, int hasta);
int consultar_saldo(cliente cli[], int nro_cliente);
int depositar(cliente cli[], int nro_cliente, int monto);
int extraer(cliente cli[], int nro_cliente, int monto);

#endif




