#include <iostream>

int linear_search(int* array, unsigned size, int value)
{
    for (int i = 0; i != size + 1; i++)
    {
        if (array[i] == value)
        {
            return i;   // вернуть индекс ежже
        }
        else if (i == size & array[i] != value)     // проверка на то что нет введенного числа
        {
            std::cerr << "There is no such number." << std::endl;
        }
    }
    return 0;
}

int main()
{
    int array[6] = {25, 321, 456, 777, 321, 32};
    int index = linear_search(array, 6, 0);
    std::cout << index;
}