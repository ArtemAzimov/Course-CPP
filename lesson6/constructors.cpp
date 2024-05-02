#include <iostream>
#include <string>

using namespace std;

class MyClass
{
	unsigned int length;
	char*        name;

public:
	MyClass(unsigned length, char* name) // : length(length), name(name) {}
	{
		this->length = length;
		this->name = name;

		cerr << "*Usual constructor*" << endl;
	}

	MyClass(const MyClass& original) // : length(original.length), name(original.name) {}
	{
		// **************************
		length = original.length;

		name = new char[length];

		for (unsigned i = 0; i < original.length; i++)
			name[i] = original.name[i];

		cerr << "*Copy constructor*" << endl;
	}

	MyClass(MyClass&& other)
	{
		length = other.length;
		name = other.name;
		other.name = nullptr;

		cerr << "*Move constructor*" << endl;
	}

	void show_name() {
		cout << name << endl;
	}

	~MyClass()
	{
		delete[] name;
	}
};

void foo(MyClass obj)
{
	obj.show_name();
}

MyClass getMyObj(unsigned length, char* str)
{
	return MyClass(length, str);
}

int main()
{
	const unsigned length = 7;
	char* str = new char[length];

	str[0] = 'B';
	str[1] = 'A';
	str[2] = 'T';
	str[3] = 'M';
	str[4] = 'A';
	str[5] = 'N';
	str[6] = '\0';

	MyClass obj(length, str); // Usual constructor

	// При сбросе в функцию по значению
	// При инициализации

	MyClass obj2(obj); // Copy constructor
	obj2.show_name();

	MyClass obj3 = std::move(getMyObj(length, str));
	obj3.show_name();

	return 0;
}

