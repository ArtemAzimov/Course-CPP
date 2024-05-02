#include <iostream>
#include <vector>
#include <algorithm>
#include <execution> // библиотека, содержащая типы политик исполнения

int main() {
    std::vector<int> v {5, 7, 2, 8, 3, 1, 9, 4, 6};
    
    // применение алгоритма sort с использованием политики исполнения parallel_policy
    std::sort(std::execution::par, v.begin(), v.end());
    
    // вывод отсортированного вектора
    for (auto elem : v) {
        std::cout << elem << \" ";
    }
    std::cout << std::endl;
    
    return 0;
}
