#include <iostream>
#include <chrono>

using namespace std::chrono;

#define MYDEFINE 3 * 4 

constexpr uint32_t factorial(uint32_t n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

constexpr uint32_t constVar = 2;
// const uint32_t constVar = 2;

uint32_t factorial_non_constexpr(uint32_t n) {
    return (n <= 1) ? 1 : n * factorial_non_constexpr(n - 1);
}

int main() {
    auto start = std::chrono::system_clock::now();
    // constexpr int result = factorial(120); // Вычисление на этапе компиляции
    auto result = factorial_non_constexpr(120);
    auto end = std::chrono::system_clock::now();
    std::cout << "Factorial of 5 is: " << result << std::endl;
    std::cout << "My define: " << 3 * 4 + 1 << std::endl;
    // constVar = 5;
    std::cout << "Const var: " << constVar << std::endl;
    std::cout << "Time: " << (end - start).count() << std::endl;
    return 0;
}