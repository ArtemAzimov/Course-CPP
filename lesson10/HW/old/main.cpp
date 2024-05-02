#include <iostream>

#include "Matrix.hpp"



int main()
{
    // Matrix m1 = {{0, 1, 2, 3}, {4, 5, 6, 7}};

    Matrix m1;
    m1.showMatrix();

    m1 = m1 << 1;
    m1.showMatrix();
}