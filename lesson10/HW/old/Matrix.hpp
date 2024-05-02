#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <initializer_list>
#include <iomanip>

using uint = unsigned int;
using initializer_matrix = std::initializer_list<std::initializer_list<int>>;



class Matrix
{
public:
    uint width;
    uint height;
    int** pmatrix;  // указатель на указатель. Спасибо ЧатГПТ

/************************************************************************************************************/
/********** CONSTRUCTORS ************************************************************************************/
/************************************************************************************************************/

    Matrix(initializer_matrix matrix)   // ЧатГПТ...
    {
        std::cout << "DEBUG: called constructor initializer list" << std::endl;
        width = matrix.size();
        height = matrix.begin()->size();

        pmatrix = new int*[width];
        for (int i = 0; i < width; i++)
        {
            pmatrix[i] = new int[height];
        }

        int i = 0;
        for (auto width : matrix)
        {
            int j = 0;
            for (auto height : width)
            {
                pmatrix[i][j] = height;
                j++;
            }
            i++;
        }

    }

    Matrix(const uint width = 2, const uint height = 3) : width(width), height(height)
    {
        std::cout << "DEBUG: called constructor Matrix" << std::endl;
        pmatrix = new int*[width]; // указатель на массив строк
        for (int i = 0; i < width; i++)
        {
            pmatrix[i] = new int[height];   // для каждой строки указатель на массив столбцов
        }

        int iter_i = 0;
        for (int i = 0; i < width; i++)     // дефолтное заполнение от 0 до n, если мы не указали контентс матрицы
        {
            for (int j = 0; j < height; j++)
            {
                pmatrix[i][j] = iter_i++;
            }
        }
    }

    Matrix(const Matrix& other)
    {
        std::cout << "DEBUG: called copy-constructor Matrix&" << std::endl;
        width = other.width;
        height = other.height;

        pmatrix = new int*[width];
        for (int i = 0; i < width; i++)
        {
            pmatrix[i] = new int[height];
        }

        int iter_i = 0;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                pmatrix[i][j] = iter_i++;
            }
    }
        
    }

    Matrix(Matrix&& other){}

    ~Matrix()
    {
        std::cout << "DEBUG: called destructor ~Matrix" << std::endl;
        delete [] pmatrix;
    }

/************************************************************************************************************/
/******** OPERATORS OVERLOADS *******************************************************************************/
/************************************************************************************************************/

    Matrix operator + (const Matrix& rhs) const  // складывает две матрицы
    {
        if (this->width != rhs.width || this->height != rhs.height)         // проверка на размер матриц
            std::cerr << "ERROR: Accepts only matrices with identical sizes";
            
        Matrix res(this->width, this->height);

        for (int i = 0; i < this->width; i++)
            for (int j = 0; j < this->height; j++)
                res.pmatrix[i][j] = this->pmatrix[i][j] + rhs.pmatrix[i][j];
        return res;
    }

    Matrix operator - (const Matrix& rhs) const  // отнимает одну матрицу от другой
    {
        if (this->width != rhs.width || this->height != rhs.height)     // проверка на размер матриц
        {
            std::cerr << "ERROR: Accepts only matrices with identical sizes" << std::endl;
        }         

        Matrix res(this->width, this->height);

        for (int i = 0; i < this->width; i++)
            for (int j = 0; j < this->height; j++)
                res.pmatrix[i][j] = this->pmatrix[i][j] - rhs.pmatrix[i][j];
        return res;
        
    }

    Matrix operator << (int pos) const  // сдвигает содержимое матрицы влево на указанное количество позиций
    {
        if (pos <= 0)
        {
            std::cerr << "ERROR: Accepts only positive values" << std::endl;
        }

        Matrix res(width, height);
        for (int i = 0; i < width; i++)
            for (int j = 0; j < height; j++)
            {
                res.pmatrix[i][j] = pmatrix[i][j + pos];
            }
        return res;;
    }








/************************************************************************************************************/
/************** METHODS *************************************************************************************/
/************************************************************************************************************/

    void showMatrix(int width = 5, char fill_character = '.')       // показывает всю матрицу
    {
        std::cout << "DEBUG: called Matrix::showMatrix" << std::endl << std::endl;
        for (int i = 0; i < this->width; i++)
        {
            for (int j = 0; j < this->height; j++)
            {
                std::cout << std::setw(width) << std::setfill(fill_character) << '[' << this->pmatrix[i][j] << ']';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // MATRIX_HPP