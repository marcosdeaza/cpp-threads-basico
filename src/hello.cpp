#include <iostream>
#include <thread>

void saludar(int id) {
    std::cout << "Hola mundo desde el hilo " << id << "\n";
}

int main() {
    std::thread hilos[5];

    for (int i = 0; i < 5; i++) {
        hilos[i] = std::thread(saludar, i);
    }
    for (int i = 0; i < 5; i++) {
        hilos[i].join();
    }

    std::cout << "terminaron todos\n";
}
