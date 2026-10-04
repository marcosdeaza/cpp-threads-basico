#include <iostream>
#include <thread>
#include <vector>
using namespace std;

// Cada thread guarda su resultado en su propia casilla de este vector
vector<long long> parciales(4);

void sumarTramo(const vector<int>& datos, int inicio, int fin, int idx) {
    long long suma = 0;
    for (int i = inicio; i < fin; ++i) suma += datos[i];
    parciales[idx] = suma; // cada thread escribe SOLO en su casilla
}

int main() {
    // Vector enorme con los números del 1 al 1.000.000
    vector<int> datos(1000000);
    for (int i = 0; i < 1000000; i++) {
        datos[i] = i + 1;
    }

    // Cada thread suma un cuarto del vector (250.000 números)
    // ref(datos) hace que el thread use el vector original y no una copia
    thread t1(sumarTramo, ref(datos), 0, 250000, 0);
    thread t2(sumarTramo, ref(datos), 250000, 500000, 1);
    thread t3(sumarTramo, ref(datos), 500000, 750000, 2);
    thread t4(sumarTramo, ref(datos), 750000, 1000000, 3);

    // Esperamos a que terminen los 4 antes de usar los resultados
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // Sumamos los resultados parciales
    long long total = 0;
    for (int i = 0; i < 4; i++) {
        cout << "Parcial " << i << ": " << parciales[i] << "\n";
        total += parciales[i];
    }
    cout << "Suma total: " << total << "\n";
    return 0;
}
