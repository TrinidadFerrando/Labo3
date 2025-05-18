#ifndef _SEMAFOROS_H
#define _SEMAFOROS_H

int crear_semaforo();
void iniciar_semaforo(int id_semaforo, int valor_inicial);
void esperar_semaforo(int id_semaforo);
void levantar_semaforo(int id_semaforo);

#endif


