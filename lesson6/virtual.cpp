#include <iostream>
#include <string>

using namespace std;

class Cat
{
public:
	Cat() { cout << "Cat" << endl; }
	~Cat() { cout << "~Cat" << endl; }

	void make_sound() { cout << "Meow!" << endl; }
};

class Tiger : public Cat
{
public:
	Tiger() { cout << "Tiger" << endl; }
	~Tiger() { cout << "~Tiger" << endl; }

	void make_sound() { cout << "Roar!" << endl; }
};

int main()
{
	{
		Cat c;
		// c.make_sound();
	} // Cat dies from cringe

	{
		Tiger t;
		// t.make_sound();
	} // Tiger dies from pleasure

	// *******************************************
	// *               LEVEL 2                   *
	// *******************************************
	
	{
		Cat* t = new Tiger; // Проявление полиморфизма
		t.make_sound();
	}

	return (0);
}
