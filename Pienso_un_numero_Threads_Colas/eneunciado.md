# 🧾 Trabajo Práctico - Programación Paralela (Hilos)

---

## 🧠 Ejercicio 01 – “Pienso un número”

Se trata de un proceso `PIENSOUNNUMERO` con varios hilos (uno por jugador).

### 🔹 Funciones del `main`:
- Recibe por parámetro la **cantidad de jugadores** (`argc`, `argv`).
- Genera un **número aleatorio del 1 al 99**.
- Declara una variable local `alguien_acerto = 0`.

- Crea un hilo `ThreadJugador` por cada jugador.
- A cada hilo le pasa:
  - El número pensado.
  - Un puntero a `alguien_acerto`.
- Espera a que terminen los hilos.
- Al finalizar, **informa quién fue el ganador**.

### 🔹 Funciones de cada `ThreadJugador`:
- Cada `N` ms (N aleatorio entre 500 y 5000), genera un número del 1 al 99, **no repetido**.
- Verifica si `alguien_acerto ≠ 0` → si es así, termina el hilo.
- Compara su número con el número pensado por el `main`.
- Si acierta:
  - Cambia `alguien_acerto` por su número de jugador.
  - Termina el hilo.
- Devuelve la cantidad de intentos que tuvo.

### ✅ Requisitos:
- Solo se puede usar como variable global el **mutex**.
- Todas las demás variables deben ser pasadas por parámetro.
- Mostrar actividad diferenciada por hilo.
- **Evitar múltiples ganadores**.
- Al finalizar, mostrar ganador y cantidad de intentos por jugador.

---
