#include <iostream>

using namespace std;

int foo(int x, int y)
{
	return (x + y) * 0.2;
}

int main()
{
	const unsigned int matrix_width  = 20;
	const unsigned     matrix_height = 20;
	
	int   array_i[matrix_width][matrix_height];
	float array_f[matrix_width][matrix_height];

	const int x = -10;
	const int y = -10;

	for (int i = 0; i < matrix_width; i++)
	{
		for (int j = 0; j < matrix_height; j++)
		{
			array_i[i][j] = foo(x + i, y + j);
		}
	}

	// ********** OUTPUT ***********

	for (int i = 0; i < matrix_width; i++)
	{
		for (int j = 0; j < matrix_height; j++)
		{
			cout << '[';

			switch (array_i[i][j])
			{
				case -5 : cout << ' '; break;
				case -4 : cout << '.'; break;
				case -3 : cout << ','; break;
				case -2 : cout << ':'; break;
				case -1 : cout << ';'; break;
				case 0  : cout << '*'; break;
				case 1  : cout << 'O'; break;
				case 2  : cout << '0'; break;
				case 3  : cout << '$'; break;
				case 4  : cout << '#'; break;
				case 5  : cout << '@'; break;
				default : cout << '?';
			}

			cout << ']';
		}
		cout << '\n';
	}

	return (0);
}