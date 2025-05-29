#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "funciones.h"


void iniciar_aleatorio(){
	srand(time(0));
}

int num_aleatorio(int desde, int hasta){
    return rand() % (hasta-desde+1) + desde;
}



