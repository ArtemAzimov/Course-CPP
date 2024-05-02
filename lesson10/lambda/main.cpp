#include <iostream>

using std::cout;
using std::endl;

const unsigned size = 10;

void foo( int* array, void (*f)(int&) )
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

void plus_one(int& x)
{
	x++;
}

void minus_one(int& x)
{
	x--;
}

int main()
{
	void (*pf)(int&);
	pf = plus_one;

	// int a = 10;
	// pf(a);

	// cout << a << endl;

	// pf = minus_one;
	// pf(a);

	// cout << a << endl;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
		array[i] = i;

	foo(array, pf);

	for (int i = 0; i < size; i++)
		cout << array[i] << '\t';
	cout << endl;
	return (0);
}