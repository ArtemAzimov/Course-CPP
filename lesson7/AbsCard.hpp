#pragma once // возможность для подключения этого класса из разных мест в программе
            // иначе препроцессор будет его подключать каждый раз когда пойдет инклуд
            // AbsCard будет подключен один раз

#include <string>

class AbsCard   // абстрактный класс
{
protected:
    int id;
    std::string name;
    unsigned salary;

public:
    AbsCard(const int id, const std::string name, unsigned salary) : id(id), name(name), salary(salary){} // инициализация констант в конструкторе

    virtual std::string getInfo() = 0; // чисто виртуальный метод / абстрактный метод
};