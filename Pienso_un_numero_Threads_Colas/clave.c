#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>

#include "clave.h"
#include "def.h"

key_t crear_clave(){
    key_t id_clave;
    id_clave = ftok("/bin/ls", CLAVE_BASE);
    if (id_clave == (key_t)-1)
    {
        printf("No puedo conseguir clave.\n");
        exit(1);
    }
    return id_clave;
}