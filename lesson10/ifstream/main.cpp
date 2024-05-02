#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdio>
#include <cmath>

#include "FileReader.hpp"

// using namespace std;
using std::cout;
using std::endl;

int main()
{
	double d = 3.14160000001;

	cout << std::setprecision(1);
	cout << std::setbase(16);
	cout << d << endl;
	cout << 1024 << endl;

	cout << std::setbase(10);
	cout << std::setfill('*');
	cout << std::setw(10) << 102400 << endl;
	cout << std::setw(10) << 1099 << endl;
	cout << std::setw(10) << 668 << endl;

	return (0);
}