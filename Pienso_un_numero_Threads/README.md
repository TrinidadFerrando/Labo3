Ejecución:  ./pienso_numero 4 (si quiero 4 jugadores)
            ./pienso_numero 3 (si quiero 3 jugadores)

Evita repeticiones por jugador, pero no entre todos los jugadores.

El main hace:
    -Lee por consola la cantidad de jugadores.
    -Genera un número (aleatorio). 
    -Crea un hilo por jugador, pasándole:
                                        Su número de jugador
                                        El número
                                        Un puntero a alguien_acerto
                                        Intentos realizados

    -Espera a que todos los hilos terminen.
    -Muestra quién ganó y cuántos intentos tuvo cada jugador.

Cada hilo: funcion_thread
    -Cada 500–5000 ms genera un número aleatorio del 1 al 99 --> sin repetidos
    -Si ya alguien acertó (alguien_acerto ≠ 0), termina.
    -Si acierta, escribe su número en alguien_acerto usando mutex.
    -Guarda cuántos intentos hizo y termina.

typedef struct {
    int id_jugagor;                    
    int numero_aleatorio;
    int *alguien_acerto;       
    int intentos;
} datos_jugador;


Única variable global permitida:  pthread_mutex_t mutex;
    (Declarada en global.c, extern en global.h.)


