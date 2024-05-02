#include <iostream>
#include <string>

using namespace std;

/* // Структура
struct triangle
{
	int a;
	int b;
	int c;
};

void foo(triangle abc)
{
	cout << abc.a << endl;
	cout << abc.b << endl;
	cout << abc.c << endl;
}

int main()
{
	// структура + указатель = лист

	int x = 100;
	int* px; // указатель - переменная, значение которой - адрес в памяти
	int& lx = x; // ссылка - ???

	px = &x; // адрес объекта
	cout << *px; // значение поинтера
	*px = 110;
	cout << x;

	char str[9] = "SUPERMAN";
	char* p_str = nullptr; // бэкслеш0 для указателей, инициализация
	char* p_str = str;
	p_str++;
	p_str = p_str + 1;

	//triangle t;

	//t.a = 10;
	//t.b = 5;
	//t.c = 9;

	return (0);
} */


// lvl 4 pointers
int main()
{
	int* p_var; // создание указателя
	p_var = new int; // int - значит 4 байта и какого типа указатель возвращать
	cout << *p_var << endl;
	*p_var = 1488;
	cout << *p_var << endl;
	cout << "adress: " << p_var << endl;

	delete p_var; // вызов когда закончили работать с данными, 

	const int size = 10;
	p_var = new int[10]; // выделение памяти
	cout << "adress: " << p_var << endl;

	for (int i = 0; i < size; i++)
		cout << *p_var++ << ' '; // прогон по адресам выделенные под p_var
	for (int i = size - 1; i >= 0; i--)
		cout << *--p_var << ' ';
	cout << endl;

	delete[] p_var; // после выделения с new - удалить выделенную память

	return(0);
}




//int foo(int arg1) {
//    if (arg1 % 2 == 0)
//        return 666;
//    else
//        return 777;
//}

//void foo(int array[], int breaker) // void - тип функции, которая ничего не возвращает. МОЖНО БЕЗ RETURN, ИНАЧЕ ВСЕГДА RETURN
//{ 
//    for (int i = 0; array[i] != breaker; i++) // сигнатура функции — void(int[], int)
//        cout << array[i];
//}
//
//bool bar() // сигнатура функции - bool()
//{
//    return true;
//}
//
//int main()
//{
//    int array[10] = { 1, 2, 3, 4, 0, 10, 5, -1 };
//
//    foo(array, -1);
//    cout << '\n';
//    foo(array, 0);
//    cout << '\n';
//
//
//
//
//
//
//
//    //int x = 10;
//    //int y = foo(x);
//
//    //cout << y << endl;
//
//    //return (0);
//
//
//
//    //int array[6] = { 4, 8, 15, 16, 23, 42 };
//
//    ////bool conditions[3];
//    ////conditions[0] = (5 < 6);
//
//
//    //char str[7] = { 'B', 'A', 'T', 'M', 'A', 'N', '\0'}; // символ '\0' - окончание строки, обязательно
//
//
//    //for (int i = 0; i < 6; i++)
//    //    cout << str[i];
//    //cout << '\n';
//    //cout << str;
//
//    //const int size = 1337;
//    //int new_array[size];  // MAGIC NUMBERS
//
//    ////for (int i = 0; i < size; i++)
//    ////    new_array
//
//
//}
