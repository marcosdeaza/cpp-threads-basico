#include <iostream>
#include <thread>
using namespace std;

void saludar(int id) {
    cout << "Hola mundo desde el hilo " << id << "\n";
}

int main() {
    thread hilos[5];

    for (int i = 0; i < 5; i++) {
        hilos[i] = thread(saludar, i);
    }
    for (int i = 0; i < 5; i++) {
        hilos[i].join();
    }

    cout << "terminaron todos\n";
}
