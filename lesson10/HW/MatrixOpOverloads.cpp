#include "MatrixBase.hpp"

const Matrix& Matrix::operator = (const Matrix& other)
{
    std::cerr << "DEBUG: operator = called" << std::endl;

    width = other.width;
    height = other.height;

    pmatrix = new int*[width];
    for (int i = 0; i < width; i++)
    {
        pmatrix[i] = new int[height];
    }

    int iter_i = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pmatrix[i][j] = other.pmatrix[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator + (const Matrix& rhs) const  // складывает две матрицы
{
    if (width != rhs.width || height != rhs.height)         // проверка на размер матриц
        std::cerr << "ERROR: Accepts only matrices with identical sizes";
        
    Matrix res(width, height);

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            res.pmatrix[i][j] = pmatrix[i][j] + rhs.pmatrix[i][j];
    return res;
}

Matrix Matrix::operator - (const Matrix& rhs) const  // отнимает одну матрицу от другой
{
    if (width != rhs.width || height != rhs.height)     // проверка на размер матриц
    {
        std::cerr << "ERROR: Accepts only matrices with identical sizes" << std::endl;
    }         

    Matrix res(width, height);

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            res.pmatrix[i][j] = pmatrix[i][j] - rhs.pmatrix[i][j];
    return res;
}

Matrix Matrix::operator << (int pos) const  // сдвигает содержимое матрицы влево на указанное количество позиций
{
    if (pos <= 0)
    {
        std::cerr << "ERROR: Accepts only positive values" << std::endl;
    }

    Matrix res(width, height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j + pos >= width)
                res.pmatrix[i][j] = 0;          // вставляет 0 как новый элемент после сдвига
            else
                res.pmatrix[i][j] = pmatrix[i][j + pos];
        }
    }
        
        return res;
    }

Matrix Matrix::operator >> (int pos) const
{
    if (pos <= 0)
    {
        std::cerr << "ERROR: Accepts only positive values" << std::endl;
    }

    Matrix res(width, height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j - pos >= width)
                res.pmatrix[i][j] = 0;          // вставляет 0 как новый элемент после сдвига
            else
                res.pmatrix[i][j] = pmatrix[i][j - pos];
        }
    }
        
        return res;
    }
                                    // ВОПРОС - оно работает, но прально ли создавать отдельный объект класса чтобы запомнить оригинал ?
Matrix Matrix::operator ++ (int)    // postfix T++  - сначала вернуть, потом прибавить
{
    Matrix res(width, height);

    for (int i = 0; i < height; i++)        // цикл чтобы вернуть данные оригинала до инкремента
        for (int j = 0; j < width; j++)
            res.pmatrix[i][j] = pmatrix[i][j];

    for (int i = 0; i < height; i++)        // цикл инкрементирует оригинал
        for (int j = 0; j < width; j++)
            pmatrix[i][j] = pmatrix[i][j] + 1;

    return res;
}

Matrix Matrix::operator -- (int)    // postfix T--  - сначала вернуть, потом убавить
{
    Matrix res(width, height);

    for (int i = 0; i < height; i++)        // цикл чтобы вернуть данные оригинала до декремента
        for (int j = 0; j < width; j++)
            res.pmatrix[i][j] = pmatrix[i][j];

    for (int i = 0; i < height; i++)        // цикл декрементирует оригинал
        for (int j = 0; j < width; j++)
            pmatrix[i][j] = pmatrix[i][j] - 1;

    return res;
}

Matrix& Matrix::operator ++ ( )    // prefix ++T   - сначала прибавить, потом вернуть
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            pmatrix[i][j] = pmatrix[i][j] + 1;
    return *this;
}

Matrix& Matrix::operator -- ( )    // prefix --T   - сначала убавить, потом вернуть
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            pmatrix[i][j] = pmatrix[i][j] - 1;
    return *this;
}

Matrix Matrix::operator - ( ) const
{
    Matrix res(width, height);

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            res.pmatrix[i][j] = -pmatrix[i][j];
    return res;
}

int& Matrix::operator () (int x, int y)
{
    return pmatrix[x][y];
}

// int const & Matrix::operator [] (int pos) const  // оператор [] принимает 1 аргумент. Гугл говорит что нужен вложенный класс для второго аргумента
