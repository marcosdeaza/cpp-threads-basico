#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int contador = 0;
std::mutex m;

void sumar(int veces) {
    for (int i = 0; i < veces; ++i) {
        std::lock_guard<std::mutex> lock(m);
        ++contador;
    }
}

int main() {
    const int hilos = 4;
    const int veces = 100000;

    std::vector<std::thread> lista;
    for (int i = 0; i < hilos; ++i) {
        lista.emplace_back(sumar, veces);
    }

    // hay que esperar a todos antes de leer el contador
    for (auto& t : lista) {
        t.join();
    }

    std::cout << "contador = " << contador
              << " (esperado " << hilos * veces << ")\n";
    return 0;
}
