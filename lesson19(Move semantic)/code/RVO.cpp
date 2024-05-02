#include <iostream>

class MyObject
{
public:
    MyObject()
    {
        std::cout << "Default Constructor" << std::endl;
    }

    MyObject(const MyObject &other)
    {
        std::cout << "Copy Constructor" << std::endl;
    }

    // MyObject(MyObject &&other) noexcept
    // {
    //     std::cout << "Move Constructor" << std::endl;
    // }
};

MyObject createObjectRVO()
{
    MyObject obj;
    // Некоторая логика и манипуляции с obj
    return obj; // Возврат объекта по значению
}

MyObject createObjectWithoutRVO(bool value)
{
    MyObject obj1;
    MyObject obj2;
    if (value){
        return obj1; // Возврат объекта по значению
    } else {
        return obj2; // Возврат объекта по значению
    }
}

int main()
{
    std::cout << "Test RVO\n";
    MyObject resultRVO = createObjectRVO(); // Инициализация с помощью возвращаемого значения функции
    std::cout << "Test Without RVO\n";
    MyObject result = createObjectWithoutRVO(true); // Инициализация с помощью возвращаемого значения функции
    return 0;
}