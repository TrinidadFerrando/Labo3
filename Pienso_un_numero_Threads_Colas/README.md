Ejecución:  ./pienso_numero 4 (si quiero 4 jugadores)
            ./pienso_numero 3 (si quiero 3 jugadores)

Evita repeticiones por jugador, pero no entre todos los jugadores.

1. main.c (pienso_numero):
    Genera el número a adivinar.
    Lo envía al tablero.c al iniciar.
    Crea los hilos jugadores.
    Espera a que todos terminen.

2. funcion_thread:
    Igual a como ya lo tenés, pero consulta al tablero si acertó mediante colas.
    Informa quién ganó y con cuántos intentos.

3. tablero.c:
    Al iniciar, espera un mensaje con el número a adivinar.
    Luego escucha los intentos y responde con:
    EVT_RTA_ACERTO_FIN si es correcto.
    EVT_RTA_NO_ACIERTO si no.


Única variable global permitida:  pthread_mutex_t mutex;
    (Declarada en global.c, extern en global.h.)


