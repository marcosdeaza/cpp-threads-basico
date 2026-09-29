#include <iostream>
#include <thread>
#include <vector>

void factorial(int number) {
    unsigned long long factorial_value = 1;
    for (int i = 2; i <= number; i++) {
        factorial_value *= i;
    }
    std::cout << "Factorial of " << number << " is "
              << factorial_value << "\n";
}

int main() {
    std::vector<int> numbers = {5, 8, 12, 15, 20};
    std::vector<std::thread> threads;

    for (int n : numbers) {
        threads.emplace_back(factorial, n);
    }
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}
