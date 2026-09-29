# cpp-threads-basico

Práctica 1 (guiada): primer programa multithreading en C++17.

El programa está en `src/Practica3_1/Practica3_1.cpp`. Lanza 5 threads que
ejecutan `greeting(id)` y espera a que terminen.

    cmake -S . -B build
    cmake --build build
    ./build/Practica3_1

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

## Otros archivos

`src/main.cpp` y `src/hello.cpp` son pruebas mías de antes (contador con
mutex y un hola mundo simple). La práctica es la de `Practica3_1`.
