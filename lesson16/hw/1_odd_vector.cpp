/*
1.  Напишите функцию, которая принимает вектор целых чисел и возвращает итератор на первый элемент, который не является четным числом.
*/ 

#include <iostream>
#include <vector>
#include <algorithm>

using uint = unsigned int;

std::vector<uint>::const_iterator findFirstOdd(std::vector<uint>& vec)
{
    std::vector<uint>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); ++it){
        if (*it % 2 != 0) { return it;}
    }
    return it;
}


int main()
{
    // std::vector<uint> vector1 {2, 4, 6, 8, 7, 10, 290, 1, 33, 20};  // - test #1 ODD NUMBERS
    std::vector<uint> vector1 {2, 4, 6, 8, 10, 290, 20};         // - test #2 NO ODD NUMBERS

    if (findFirstOdd(vector1) == vector1.end()){
        std::cout << "---* There are no odd numbers in this vector." << std::endl;
    }
    else{
        std::cout << *(findFirstOdd(vector1)) << std::endl;
    }

    return 0;
}
