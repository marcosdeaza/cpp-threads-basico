#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void greeting(int id) {
    cout << "Hello from thread " << id << " (real id: "
              << this_thread::get_id() << ")\n";
}

int main() {
    vector<thread> threads;

    for (int i = 1; i <= 5; i++) {
        threads.emplace_back(greeting, i);
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}
