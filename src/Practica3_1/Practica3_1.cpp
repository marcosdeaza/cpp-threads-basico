#include <iostream>
#include <thread>
#include <vector>

void greeting(int id) {
    std::cout << "Hello from thread " << id << " (real id: "
              << std::this_thread::get_id() << ")\n";
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 1; i <= 5; i++) {
        threads.emplace_back(greeting, i);
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}
