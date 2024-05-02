#include <iostream>
#include <string>

using namespace std;

int sum(int a, int b)
{
	return (a + b);
}

float sum(float a, float b)
{
	return (a + b);
}

string sum(char a, char b) // WHAT IS THE STRING?
{
	string ret;
	ret.push_back(a);
	ret.push_back(b);

	return ret;
}

// struct maybe?

int main()
{
	cout << "int: " << sum(3, 3) << endl;
	cout << "float: " << sum(3.0f, 4.0f) << endl;
	cout << "string: " << sum('O', 'K') << endl;

	return (0);
}