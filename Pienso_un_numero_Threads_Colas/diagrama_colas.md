```mermaid
sequenceDiagram
    autonumber
    participant Tablero
    participant Jugador
    participant Hilo_1
    participant Hilo_2

    Note over Jugador: Proceso Jugador crea hilos
    Jugador ->> Hilo_1: pthread_create()
    Jugador ->> Hilo_2: pthread_create()

    loop hasta que alguien acierte
        Hilo_1 ->> Tablero: enviar_mensaje(MSG_TABLERO, id_hilo, EVT_CONSULTA_NUMERO, "n")
        Tablero ->> Hilo_1: recibir_mensaje(id_hilo) → EVT_RTA_NOACERTO_SIGUE o EVT_RTA_ACERTO_FIN

        Hilo_2 ->> Tablero: enviar_mensaje(MSG_TABLERO, id_hilo, EVT_CONSULTA_NUMERO, "m")
        Tablero ->> Hilo_2: recibir_mensaje(id_hilo) → EVT_RTA_NOACERTO_SIGUE o EVT_RTA_ACERTO_FIN
    end

    Tablero -->> Jugador: Termina juego cuando alguien acierta
    Jugador ->> Hilo_1: pthread_join()
    Jugador ->> Hilo_2: pthread_join()
    Jugador ->> Jugador: Finaliza
