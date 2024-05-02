#include <iostream>
#include "MatrixBase.hpp"

int main()
{
    Matrix m1 = {{0, 1, 2, 3},
                 {4, 5, 6, 7}};
    m1.showMatrix();

    Matrix m2 = {{0, -1, 2, 3},
                 {4, 5, 6, 7}};
    m2.showMatrix();
    m1.showMatrix();

    // Matrix m2;
    // m2 = m1++;          // postfix - сначала возвращает оригинал, потом инкрементирует оригинал
    // m2.showMatrix();    // значение оригинала (НЕ инкрементированного)
    // m1.showMatrix();    // оригинал (инкрементированный)

    // Matrix m2;
    // m2 = ++m1;          // prefix - сначала инкрементирует оригинал, потом возвращает его по ссылке
    // m2.showMatrix();    // значение из ссылки (инкрементированный)
    // m1.showMatrix();    // оригинал (инкрементированный)

    // m1 = -m1;
    // m1.showMatrix();

    // std::cout << m1(1,1) << std::endl;
}