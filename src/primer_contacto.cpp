#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

int contador = 0;
mutex m;

void sumar(int veces) {
    for (int i = 0; i < veces; ++i) {
        lock_guard<mutex> lock(m);
        ++contador;
    }
}

int main() {
    const int hilos = 4;
    const int veces = 100000;

    vector<thread> lista;
    for (int i = 0; i < hilos; ++i) {
        lista.emplace_back(sumar, veces);
    }

    // hay que esperar a todos antes de leer el contador
    for (auto& t : lista) {
        t.join();
    }

    cout << "contador = " << contador
              << " (esperado " << hilos * veces << ")\n";
    return 0;
}
