#include <iostream>

using namespace std;

 //I.
 
class Rectangle
{
public:
    int coef = 10;
private: // Модификатор доступа, по дефолту приватные // Публичные, открытые данные
    unsigned width; // Данные / атрибуты класса / поле класса / члены класса
    unsigned height;

    void draw_top_or_bottom()
    {
        for (unsigned i = 0; i < width; i++)
        {
            cout << '#';
        }
        cout << endl;
    }

    void draw_center()
    {
        for (unsigned i = 0; i < (height - 2); i++)
        {
            for (unsigned j = 0; j < (width - 2); j++)
            {
                cout << ' ';
            }
            cout << '#' << endl;
        }
    }

public:
    void set_width(const unsigned width) // width одинаково называются переменные
    {
       this->width = width * coef; // this — указатель на объект этого класса
    }
    void set_height(const unsigned height)
    {
        this->height = height * coef;
    }
    void draw_rectangle()
    {
        draw_top_or_bottom();
        draw_center();
        draw_top_or_bottom();
    }
};

int main()
{
    Rectangle rectum;
    rectum.coef = 15;
    rectum.set_height(5);
    rectum.set_width(4);
    rectum.draw_rectangle();

    Rectangle rectum2;
    rectum2.set_height(1);
    rectum2.set_width(1);
    rectum2.draw_rectangle();
}

class Unit
{
protected: // защищенные атрибуты, методы - доступ только у потомков класса
	unsigned int _HP;
	unsigned int _stamina;
	unsigned int _magic;
public:
	Unit(unsigned hp, unsigned stamina, unsigned magic) // Конструктор - метод, который вызывается при создании объекта класса
	{
		_HP = hp;
		_stamina = stamina;
		_magic = magic;
	}

	~Unit() {} // Деструктор - метод, который вызывается при уничтожении объекта класса

	void getDamage(unsigned damage)
	{
		_HP = (_HP - damage) > _HP ? 0 : (_HP - damage); // проверка на переполнение unsigned
	}

	void useFireBall()
	{
		
	}
};

class UnitBoss : public Unit // наследование, приватные атрибуты не наследуются
{
public:
	UnitBoss() : Unit(5000, 5000, 5000) {} // Прописывание конструктора по умолчанию, т.к. не вызывается Unit без аргументов
	~UnitBoss() {}
}; // !!! можно перегрузить конструктор

int main()
{
	Unit gg(100, 500, 1000);
	UnitBoss boss;
}




/*
class DataInit
{
	int data = 100; // Плохой способ, с константами норм

	DataInit()		// В теле конструктора. Для переменных как раз
	{		
	data = 100;
	}

	DataInit(int arg) : data(arg) {}	// константа должна быть инициализирована. Для переменных как раз
};

*/


class Animal
{
	string sound;
public:
	Animal(string str) : sound(str) {} // способ инициализации данных
	void make_sound();
};

class Cat : public Animal
{
public: 
	void make_sound();
};

int main()
{

}