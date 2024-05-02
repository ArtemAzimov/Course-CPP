#include <iostream>
#include <vector>

int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    for (size_t i = 0; i < 100; i++)
    {
        /* code */
    }
    

    for (auto& number : numbers)
    {
        // std::cout << number << " ";
        ++number;
        //////////////////////////////// 1000 lines of code
    }

    std::cout << '\n';
    for (int number : numbers)
    {
        std::cout << number << " ";
        ++number;
    }
    std::cout << '\n';
    // Вывод: 1 2 3 4 5

    std::string message = "Hello";

    for (char ch : message)
    {
        std::cout << ch << " ";
    }

    int massiv[] = {1,2,3,4,5};
    for (int it: massiv) {
        std::cout << it << " ";
    }
}