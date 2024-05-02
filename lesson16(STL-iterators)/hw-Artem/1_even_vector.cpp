// 1. Напишите функцию, которая принимает вектор целых чисел и возвращает итератор на первый элемент, который не является четным числом.

#include <iostream>
#include <vector>
#include <algorithm>

using uint = unsigned int;

// Что ретурнить если нечетное число не найдено?
std::vector<uint>::const_iterator findFirstEven(std::vector<uint> const& vec)
{
    std::vector<uint>::const_iterator it = vec.cbegin();
    for (; it != vec.end(); ++it){
        if (*it % 2 != 0) 
        { return it;}
    }
    return it;
}


int main()
{
    // std::vector<uint> vector1{2, 4, 6, 8, 7, 10, 290, 1, 33, 20};
    std::vector<uint> vector1{2, 4, 6, 8, 10, 290, 32, 20};
    // std::vector<uint> vector1 {2, 4, 6, 8, 10, 290, 20};
    auto it = findFirstEven(vector1);
    std::cout << *it << std::endl;
    std::cout << *(vector1.end()) << std::endl;


    return 0;
}
