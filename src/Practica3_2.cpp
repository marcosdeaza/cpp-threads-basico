#include <iostream>
#include <thread>
using namespace std;

void factorial(int number) {
    unsigned long long factorial_value = 1;
    for (int i = 2; i <= number; i++) {
        factorial_value = factorial_value * i;
    }
    cout << "Factorial of " << number << " is "
              << factorial_value << "\n";
}

int main() {
    thread t1(factorial, 5);
    thread t2(factorial, 8);
    thread t3(factorial, 12);
    thread t4(factorial, 15);
    thread t5(factorial, 20);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}
