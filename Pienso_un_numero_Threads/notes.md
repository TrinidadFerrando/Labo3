# 🧵 Guía genérica de estructura de `main()` con hilos en C (ANSI C - C89)

Esta estructura sirve como base para cualquier trabajo práctico que utilice `pthread` en C, sin importar la temática.

---

## ✅ PASOS GENERALES DEL `main()`

---

### 1️⃣ Librerias

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>     /* usleep() */

#include "global.h"     /* mutex, variables globales */
#include "thread.h"     /* funciones de hilos */
#include "funciones.h"  /*funciones del aleatorio*/


---
### 2️⃣ Inicializar parámetros generales
```c
int cant_hilos = 1;

pthread_t *id_hilo;
la_variable_de_mi_estrucutra_de_dato *puntero_contenido_estructura_dato     /*Ejemplo: tipo_jugador *datos_thread;*/
pthread_attr_t 	atributos;

int i;

---
### 3️⃣ Leo la cantidad de hilos que voy a tener
```c
if (argc > 1)
    cant_hilos = atoi(argv[1]);

---
### 4️⃣️(optativo)-Inicializo la elección de números aleatorios 
```c
iniciar_aleatorio();

---
### 5️⃣ Reservo un espacio en memoria para *los hilos* y *sus datos*
```c
/*Los hilos: */
id_hilo = (pthread_t*)malloc(sizeof(pthread_t)*cant_hilos);

/*Sus datos: */
datos_hilo = (la_variable_de_mi_estrucutra_de_dato*) malloc(sizeof(la_variable_de_mi_estrucutra_de_dato)*cant_hilos);


---
### 6️⃣ Inicializo los atributos del hilo
```c
pthread_attr_init(&atributos);
pthread_attr_setdetachstate(&atributos, PTHREAD_CREATE_JOINABLE);


---
### 7️⃣Inicializo el mutex
```c
pthread_mutex_init(&mutex, NULL);


---
### 8️⃣ ️Creo hilos
```c
for (i = 0; i < cant_hilos; i++) {
    datos_hilos[i].id = i;
    /*aca tengo que poner los datos de la estructura que declare en mi def.h y asignales un valor*/
    pthread_create(
        &id_hilo[i],
        &atributos,/*llamo a la direc de los atributos que declare*/ 
        funcion_thread/*aca pongo el nombre de la funcion que cree en threads.h*/, 
        (void *)&datos_hilos[i]/*llamo a la direc del contenido de la estructura de datos para que loopee*/
        );
}

---
### 9️⃣ Logica principal - Aca codeo lo que me pidan en el enunciado
```c
while (condicion_de_trabajo) {
    pthread_mutex_lock(&mutex);
    /*trabajo que tenga que hacer el hiilo*/
    pthread_mutex_unlock(&mutex);
    usleep(1000);  // espera en milisegundos
}


---
### 🔟 Finalización de hilos
```c
for (i = 0; i < cant_hilos; i++) {
    pthread_join(id_hilos[i], NULL);
    /*printf si quiero que muestre algun mensaje de fin*/
}

---
### 1️⃣1️⃣ Liberar recursos ¿?
```c
free(id_hilos);
free(datos_hilos);
pthread_mutex_destroy(&mutex);


---
### 🧠 Estructura mental resumida
```c
    1. Incluir headers
    2. Leer argumentos / inicializar variables
    3. Reservar memoria
    4. Inicializar atributos y mutex
    5. Crear hilos
    6. Ejecutar lógica del hilo principal (opcional)
    7. Esperar a que terminen los hilos
    8. Liberar recursos



---

## ✅ PASOS GENERALES DEL `void *funcion_thread(void *parametro)` - `thread.c`

---

### 1️⃣ Librerias

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "def.h"       // Constantes como CANT_CARTON, BOLILLA_HASTA, etc.
#include "global.h"    // Variables globales: mutex, g_control, etc.

---
### 2️⃣ Inicializar parámetros generales
```c
int resultado_local = 0; /*inicializo las variables locales que declaré en mi global*/
int vector_local[TAM] = {0};

int i; 


la_variable_de_mi_estrucutra_de_dato *p_datos = (la_variable_de_mi_estrucutra_de_dato *)parametro; /*Castear el parámetro recibido*/
tipo1 valor1 = p_datos->campo1;   //Accedés a los campos de la estructura
tipo2 valor2 = p_datos->campo2;   //Accedés a los campos de la estructura


/*Ejemplo:
tjugador *datos_jugador = (tjugador *)parametro;
id_jugador = datos_jugador->nro_jugador;
bolillas_sorteadas = datos_jugador->bolillas;
*/


---
### 3️⃣ Creo bucle de trabajo 
---
Mientras el trabajo no esté completo:
    1. Accedé al recurso compartido con pthread_mutex_lock(...).
    2. Realizá el procesamiento que necesite sincronización.
    3. Liberá el recurso con pthread_mutex_unlock(...).
    4. Dormí unos milisegundos para no saturar CPU. /*usleep*/
/*Ejemplo:
  for (i = 0; i < CANT_CARTON; i++) {
    encontrado = 0;
    while (encontrado == 0) {
      bolilla = rand() % (BOLILLA_HASTA + 1 - BOLILLA_DESDE) + BOLILLA_DESDE;
      encontrado = 1;
      for (j = 0; j < CANT_CARTON; j++) {
        if (bolilla == carton[j])
          encontrado = 0;
      }
    }
    carton[i] = bolilla;
  }

  while (done == 0) {
    pthread_mutex_lock(&mutex);
    if (g_control != 0) {
      g_control--;
      if (g_carton_lleno == 0) {
        for (i = 0; i < CANT_CARTON; i++) {
          if (carton[i] != 0) {
            for (j = 0; j < BOLILLA_HASTA; j++) {
              if (carton[i] == bolillas[j] && carton[i] != 0) {
                carton[i] = 0;
                cantidad_aciertos++;
              }
            }
          }
        }
        printf("JUGADOR %d ", nro_jugador + 1);
        for (j = 0; j < CANT_CARTON; j++) {
          printf(" %02d ", carton[j]);
        }
        if (cantidad_aciertos == CANT_CARTON) {
          g_carton_lleno = nro_jugador + 1;
        }
        printf(" Aciertos=%d g_control=%d g_carton_lleno=%d\n",
               cantidad_aciertos, g_control, g_carton_lleno);
      } else {
        done = 1;
      }
    }
    pthread_mutex_unlock(&mutex);

    usleep(TIEMPO_COMPRUEBA * 1000);
  };
  */

---
### Finalizar el hilo y devolver resultados
```c
p_datos->resultado = resultado_local;/*Guardo el resultado final del procedimienot que tenia que hacer el hilo*/
pthread_exit((void *)"Listo");

