```mermaid
sequenceDiagram
    box Jugador
        participant Hilo1
        participant Hilo2
        %% Podés seguir agregando más hilos acá
    end
    participant Tablero

    Hilo1->>Tablero: Enviar intento
    Tablero-->>Hilo1: ¿Acertó?

    Hilo2->>Tablero: Enviar intento
    Tablero-->>Hilo2: ¿Acertó?

    Note over Tablero: Si nadie acierta,\nse sigue intentando