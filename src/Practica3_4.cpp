#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void longTask() {
    cout << "[hilo de fondo] Empezando a tarea larga en segundo plano...\n";
    // Simula trabajo lento (por ejemplo escribir a disco o llamar a una API)
    this_thread::sleep_for(chrono::seconds(2));
    cout << "[hilo de fondo] tarea larga completada.\n";
}

int main() {
    cout << "[main] Arrancando la aplicacion...\n";

    thread workerLongTask(longTask);
    workerLongTask.detach(); // el thread se independiza: ya no podemos hacer join() sobre él

    cout << "[main] Haciendo otras cosas mientras la tarea se ejecuta...\n";

    // Con 500 ms el main termina ANTES que el hilo de fondo (que tarda 2000 ms)
    // Con 3000 ms el main espera lo suficiente para que el hilo acabe
    this_thread::sleep_for(chrono::milliseconds(500));

    cout << "[main] Terminando el programa.\n";
    return 0;
    // Cuando el main termina, el programa se lleva todos sus threads
    // (también los detached), hayan acabado o no
}
