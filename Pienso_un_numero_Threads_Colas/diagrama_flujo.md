sequenceDiagram
    box Jugador
        participant Main
        participant Hilo1
        participant Hilo2
    end
    participant Tablero

    Main->>Hilo1: Crear hilo 1
    Main->>Hilo2: Crear hilo 2

    loop Mientras no acierte
        Hilo1->>Tablero: MSG_INTENTO {id_jugador = 1, numero}
        alt Acierto
            Tablero-->>Hilo1: MSG_RESULTADO {acierto = 1}
        else
            Tablero-->>Hilo1: MSG_RESULTADO {acierto = 0}
        end
    end

    loop Mientras no acierte
        Hilo2->>Tablero: MSG_INTENTO {id_jugador = 2, numero}
        alt Acierto
            Tablero-->>Hilo2: MSG_RESULTADO {acierto = 1}
        else
            Tablero-->>Hilo2: MSG_RESULTADO {acierto = 0}
        end
    end

    Note over Tablero: Si un hilo acierta,\navisa al resto para terminar
