#include "MatrixBase.hpp"

void Matrix::showMatrix(int width, char fill_character)       // показывает всю матрицу
{
    std::cout << "DEBUG: called Matrix::showMatrix" << std::endl << std::endl;
    for (int i = 0; i < Matrix::height; i++)
    {
        for (int j = 0; j < Matrix::width; j++)
        {
            if (pmatrix[i][j] < 0)       // чтобы красиво выводились отрицательные элементы матрицы
                std::cout << std::setw(width) << std::setfill(fill_character) << '[' << this->pmatrix[i][j] << ']';
            else
                std::cout << std::setw(width) << std::setfill(fill_character) << '[' << ' ' << this->pmatrix[i][j] << ']';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}