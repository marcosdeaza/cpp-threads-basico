# cpp-threads-basico

Prácticas de threads en C++17. Cada práctica es un archivo en `src/`.

    cmake -S . -B build
    cmake --build build
    ./build/Practica3_1

## Práctica 1: primer programa multithreading

`src/Practica3_1.cpp` lanza 5 threads que ejecutan `greeting(id)` y espera a
que terminen.

![salida](img/practica3_1.png)

**1) ¿Cómo lanzas los threads?**
Creo un `std::thread` pasándole la función y su id, y lo guardo en un
`vector`. Se hace dentro de un bucle, así salen 5 seguidos.

**2) ¿Cómo esperas a que terminen?**
Con `join()` en otro bucle aparte, después de lanzarlos todos. Hasta que no
acaban los 5, el `main` no sigue.

**3) ¿Qué llama la atención?**
El orden no es siempre el mismo y a veces las líneas salen mezcladas, porque
los threads escriben en `cout` a la vez. Los ids reales son distintos en cada
thread y cambian en cada ejecución.

## Práctica 2: paso de argumentos a threads

`src/Practica3_2.cpp` lanza un thread por cada número (5, 8, 12, 15 y 20) y
cada uno calcula su factorial. El número se lo paso como argumento al crear el
thread. El `main` espera a todos con `join()`.

    ./build/Practica3_2

Uso `unsigned long long` porque con `int` el factorial se desborda desde el
13. Con 20 ya es casi el máximo que cabe.

Línea temporal (el tiempo va hacia la derecha):

    main  |crea T1..T5|-- join T1 -- join T2 -- ... -- join T5 --|fin
    T1 5!             |###|
    T2 8!             |####|
    T3 12!            |#####|
    T4 15!            |######|
    T5 20!            |#######|

Los 5 threads nacen casi a la vez desde el `main`. Cada uno termina cuando le
toca, así que los resultados no salen siempre en el mismo orden. El `main` no
acaba hasta hacer `join` a todos.

## Prueba anterior

`src/primer_contacto.cpp` es una prueba mía de antes: un contador compartido
protegido con mutex.
