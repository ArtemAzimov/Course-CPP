#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2;

    // Стандартный способ копирования элементов
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));

    // Использование move итератора для перемещения элементов
    std::move(vec1.begin(), vec1.end(), std::back_inserter(vec2));

    std::cout << "vec1: ";
    for (const auto& x : vec1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "vec2: ";
    for (const auto& x : vec2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}