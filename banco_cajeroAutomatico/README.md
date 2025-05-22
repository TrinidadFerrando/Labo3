```mermaid
sequenceDiagram
    participant Cajero as Cajero_automático
    participant Banco

    Cajero->>Banco: EVT_MENSAJE\ncontenido_msg = "iniciar sesión"
    Banco-->>Cajero: EVT_RTA_MENSAJE\n"Bienvenido &nro_cliente. Ingrese la operación que desea realizar"

    Cajero->>Banco: EVT_CONSULTA_SALDO\ncontenido_msg = nro_cliente
    alt Saldo OK
        Banco-->>Cajero: EVT_RTA_SALDO\ncontenido_msg = nro_cliente + saldo
    else Error
        Banco-->>Cajero: EVT_RTA_SALDO_NOK
    end

    Cajero->>Banco: EVT_DEPOSITO\ncontenido_msg = nro_cliente + importe
    alt Depósito OK
        Banco-->>Cajero: EVT_RTA_DEPOSITO_OK\ncontenido_msg = nro_cliente + saldo
    else Error
        Banco-->>Cajero: EVT_RTA_DEPOSITO_NOK
    end

    Cajero->>Banco: EVT_EXTRACCION\ncontenido_msg = nro_cliente + saldo
    alt Extracción OK
        Banco-->>Cajero: EVT_RTA_EXTRACCION_OK\ncontenido_msg = nro_cliente + saldo
    else Error
        Banco-->>Cajero: EVT_RTA_EXTRACCION_NOK
    end

