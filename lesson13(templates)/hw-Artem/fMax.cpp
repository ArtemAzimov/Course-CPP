#include <iostream>
#include <string>

template<typename T>                    // Единовременно работает только с одним типом. Char и др. массивы не принимает.
T maxFunc(const T& arg1, const T& arg2)
{
    if (arg1 > arg2) return arg1;
    else return arg2;
}

template<typename T>
T maxFunc(const T& arg1, const T& arg2, const T& arg3)
{
    unsigned arraysize = 3;
    T array[arraysize] {arg1, arg2, arg3};
    T temp;
    for (int i = 0; i < arraysize-1; i++)
    {
        if (array[i] > array[i+1])
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
    return array[arraysize-1];
}

template<typename T>
T maxFunc(const T& arg1, const T& arg2, const T& arg3, const T& arg4)
{
    unsigned arraysize = 4;
    T array[arraysize] {arg1, arg2, arg3, arg4};
    T temp;
    for (int i = 0; i < arraysize-1; i++)
    {
        if (array[i] > array[i+1])
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
    return array[arraysize-1];
}



int main()
{
    std::cout << "....2 ARGUMENTS:   " << maxFunc(3, 5) << std::endl;

    std::cout << "....3 ARGUMENTS:   " << maxFunc(98, 577, 3) << std::endl;

    std::cout << "....4 ARGUMENTS:   " << maxFunc(228, 55, 9000, 42) << std::endl;

    return 0;
}