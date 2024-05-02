//--------ДОМАШНЕЕ ЗАДАНИЕ ОТ 09.02.2023---------
//Вводите в программу (через cin) дробное число в переменную a, затем такое же b и также x. 
//Если число x входит в диапазон от a до b, вывести "X is in range a - b", иначе "X is out of range a - b". 
//Сделайте также проверку, что a меньше b, если это не так выводите "Range is incorrect".

# include <iostream>

using namespace std;

int main() {
	double a = 0;
	double b = 0;
	double x = 0;

	cout << "Write number 'a': ";
	cin >> a;
	cout << "Write number 'b': ";
	cin >> b;

	if (a < b) {
		cout << "Write number 'x': ";
		cin >> x;
		if (x > a && x < b) {
			cout << "X is in range a - b";
		}
		else {
			cout << "X is out of range a - b";
		}
	}
	else {
		cout << "Range is incorrect.";
	}
}