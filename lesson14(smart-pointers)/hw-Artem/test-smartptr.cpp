#include <iostream>
#include "smartptr.hpp"

int main() {
    // Создаем указатель и переменную типа int по значению, присваиваем 5
    SmartPointer<int> ptr(new int(5));

    // Доступ к переменной через указатель
    std::cout << "Interger value: " << *ptr << std::endl;

    // Создаем копию при помощи копирующего конструктора
    SmartPointer<int> ptr2 = ptr;

    // Выводим значение переменной через ptr2
    std::cout << "Interger value: " << *ptr2 << std::endl;

    // Гарантировано удалит значение в памяти
    ptr2 = nullptr;
