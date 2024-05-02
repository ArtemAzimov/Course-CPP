#include <iostream>
#include <string>

using namespace std;

class Based
{
protected:
	char* str;

public:
	Based() : str(nullptr) {}
	Based(const string& _string)
	{
		cerr << "Based" << endl;

		const unsigned length = _string.length() + 1;

		str = new char[length];

		for (unsigned i = 0; i < length; i++)
			str[i] = _string[i];
	}

	virtual ~Based() {
		delete[] str;
		cerr << "DEBUG: deleted str" << endl;
	}

	// *******************************************
	virtual void show() { cout << str << endl; }
	// *******************************************
};

class Libtard : public Based
{
	char* str2;

public:
	Libtard() : str2(nullptr) {}
	Libtard(const string& _string, const string& _string2) : Based(_string)
	{
		cerr << "Libtard" << endl;

		const unsigned length = _string2.length() + 1;

		str2 = new char[length];

		for (unsigned i = 0; i < length; i++)
			str2[i] = _string2[i];
	}

	~Libtard() {
		delete[] str2;
		cerr << "DEBUG: deleted str2" << endl;
	}

	// ****************************************************
	void show() override { cout << str << endl << str2 << endl; }
	// ****************************************************
};

Based* bar(char c)
{
	if (c == '1')
		return new Based("1");
	else
		return new Libtard("1", "2");
}

int main()
{
	// {
	// 	Based bale("I'm batman");
	// 	bale.show();
	// }

	{
		Based* whoami = bar('2');
		// указатель на базовый класс может также указывать на объект дочернего класса
		whoami->show();

		delete whoami;
	}

	return (0);
}

// todo: Конструктор копии, конструктор перемещения
// ? Классы дочки взаимозазаменяемы с классом-родителем
// ! В каком порядке вызываются конструкторы и деструкторы
// * Виртуальные методы. Виртуальные деструкторы
// todo: Принцип единой отвественности
// ? Таблица виртуальных методов

// ******************
// * show -> Based
// * show -> Libtard
// ******************