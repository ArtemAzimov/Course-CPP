#include <iostream>

using namespace std;

//float sub(int a, float b)
//{
//	return (a - b);
//}
//
//float sub(float a, float b)
//{
//	return (a - b);
//}
//
//int main()
//{
//	cout << sub(2, 3.14) << '\n';
//	cout << sub(2.1f, 3.8f);	
//}


//void foo(int x)
//{
//	cout << "x: " << x << endl;
//	if (x < 0)
//		return;
//	foo(x - 1);
//	cout << "x2: " << x << endl;
//}
//
//int main()
//{
//	foo(5);
//}

int foo(int x, int y)
{
	return (x + y) * 0.2;
}

int main()
{
	//00000011 = 3; - положит число
	//10000011 = -3;
	//11111100 = -3; - реальное представление отриц чисел в компе

	const unsigned int matrix_width = 20; // unsigned - только положительный int - кол-во столбцов
	const unsigned matrix_height = 20;  // по умолчанию int - кол-во строк

	// [1, 0 ,3] // 2, 3
	// [2, 4, 6]

	int array_i[matrix_width][matrix_height]; // matrix
	float array_i[matrix_width][matrix_height];

	array_i[1][2]; // начинается с 0

	const int x = -10;
	const int y = -10;

	for (int i = 0; i < matrix_width; i++) // проход по матрице сначала строка 1 - столбец столбец... строка 2 - столбец столбец
	{
		for (int j = 0; j < matrix_height; j++)
		{
			array_i[i][j] = foo(x + i, y + j);
		}
	}

	// ********OUTPUT*********

	for (int i = 0; i < matrix_width; i++) // проход по матрице сначала строка 1 - столбец столбец... строка 2 - столбец столбец
	{
		for (int j = 0; j < matrix_height; j++)
		{
			cout << array_i[i][j];
		}
		cout << endl;
	}
}