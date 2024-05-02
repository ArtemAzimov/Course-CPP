#ifndef MATRIX_BASE_HPP
#define MATRIX_BASE_HPP

#include <iostream>
#include <initializer_list>
#include <iomanip>

class Matrix
{
private:
    using uint               =  unsigned int;
    using initializer_matrix =  std::initializer_list<std::initializer_list<int>>;
    uint    width;
    uint    height;
    int**   pmatrix;  // указатель на указатель. Спасибо ЧатГПТ

public:
/* CONSTRUCTORS */
    Matrix(initializer_matrix matrix)
    {
        std::cout << "DEBUG: called constructor initializer list" << std::endl;
        width = matrix.begin()->size(); 
        height = matrix.size();

        pmatrix = new int*[height];
        for (int i = 0; i < height; i++)
        {
            pmatrix[i] = new int[width];
        }

        int i = 0;
        for (auto row : matrix)
        {
            int j = 0;
            for (auto elem : row)
            {
                pmatrix[i][j] = elem;
                j++;
            }
            i++;
        }
    }

    Matrix(const uint width = 3, const uint height = 2) : width(width), height(height)
    {
        std::cout << "DEBUG: called constructor Matrix" << std::endl;
        pmatrix = new int*[height];        // указатель на массив указателей
        for (int i = 0; i < height; i++)
        {
            pmatrix[i] = new int[width];   // каждый указатель в массиве указателей указывает на свой инт
        }

        int iter_i = 0;
        for (int i = 0; i < height; i++)     // дефолтное заполнение от 0 до n, если мы не указали контентс матрицы
        {
            for (int j = 0; j < width; j++)
            {
                pmatrix[i][j] = iter_i++;
            }
        }
    }

    Matrix(const Matrix& other)
    {
        std::cout << "DEBUG: called copy-constructor Matrix&" << std::endl;
        *this = other;
    }

    Matrix(Matrix&& other){}        

    ~Matrix()
    {
        std::cout << "DEBUG: called destructor ~Matrix" << std::endl;
        delete [] pmatrix;
    }

/* OPERATOR OVERLOADS */
    const Matrix& operator = (const Matrix& other); // спасибо, учител. Перегрузка оператора присваивания, без него не работает конструктор копирования
    Matrix operator + (const Matrix& rhs) const;
    Matrix operator - (const Matrix& rhs) const;
    Matrix operator << (int pos) const;             // спасибо, учител
    Matrix operator >> (int pos) const;
    Matrix operator ++ (int pos);       // postfix increment T++
    Matrix operator -- (int pos);       // postfix decrement T--
    Matrix& operator ++ ( );            // prefix increment ++T
    Matrix& operator -- ( );            // prefix decrement --T
    Matrix operator - ( ) const;        // унарный оператор -
    int& operator () (int x, int y);    // возвращает ссылку на элемент (инт) матрицы
    // int const & operator [] (int pos) const;  // ВОПРОС - const & именно в таком порядке, по другому компайлер ругается. И зачем два раза const ? 


/* METHODS */
    void showMatrix(int width = 5, char fill_character = ' ');
};

#endif // MATRIX_BASE_HPP