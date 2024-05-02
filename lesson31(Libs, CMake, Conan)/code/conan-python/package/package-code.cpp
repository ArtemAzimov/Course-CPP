#include <iostream>
#include "package-code.hpp"

// factorial.cpp
int factorial(int n) {
    std::cout << "factorial " << n << std::endl;
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}