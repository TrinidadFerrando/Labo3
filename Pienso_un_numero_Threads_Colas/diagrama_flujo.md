sequenceDiagram
    box Jugador
        participant Main
        participant Hilo1
        participant Hilo2
    end
    participant Tablero

    Main->>Hilo1: Crear hilo 1
    Main->>Hilo2: Crear hilo 2

    alt Hilo 1 activo
        Hilo1->>Tablero: EVT_INTENTO\ncontenido_msg = id_jugador: 1, número
        alt [Número correcto]
            Tablero-->>Hilo1: EVT_RTA_OK\ncontenido_msg = ¡Adivinaste!
        else [Número incorrecto]
            Tablero-->>Hilo1: EVT_RTA_NOK\ncontenido_msg = Intentá de nuevo
        end
    end

    alt Hilo 2 activo
        Hilo2->>Tablero: EVT_INTENTO\ncontenido_msg = id_jugador: 2, número
        alt [Número correcto]
            Tablero-->>Hilo2: EVT_RTA_OK\ncontenido_msg = ¡Adivinaste!
        else [Número incorrecto]
            Tablero-->>Hilo2: EVT_RTA_NOK\ncontenido_msg = Intentá de nuevo
        end
    end

    Note over Tablero: Si un hilo acierta, se notifica el fin del juego
