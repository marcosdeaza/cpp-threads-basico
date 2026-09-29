#include <iostream>
#include <thread>

void factorial(int number) {
    unsigned long long factorial_value = 1;
    for (int i = 2; i <= number; i++) {
        factorial_value = factorial_value * i;
    }
    std::cout << "Factorial of " << number << " is "
              << factorial_value << "\n";
}

int main() {
    std::thread t1(factorial, 5);
    std::thread t2(factorial, 8);
    std::thread t3(factorial, 12);
    std::thread t4(factorial, 15);
    std::thread t5(factorial, 20);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}
