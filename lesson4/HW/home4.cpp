#include <iostream>
#include <locale.h>

using namespace std;

struct t_list // структура нода
{
	int data; // данные нода
	t_list* next; // указатель на самого себя (текущий нод)
};

//func #1
t_list* create_node(int data) // создать ноду в динамической памяти, вернуть на нее указатель
{
	t_list head_node;
	head_node.data = data;
	head_node.next = nullptr;
	return &head_node;
}

//func #2
void push_node(t_list** head, t_list* node) // принимает указатель на указатель первой ноды, новую ноду ???
{
	cout << "Вызвана push_node с аргументами: " << '\n' << "head........." << head << '\n' << "node........." << node << '\n' << '\n';

}

//func #3
void show_list(t_list* head)
{
	for (; head != nullptr; head++)
		cout << head;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	int list_size = 0;
	int inp_data = 0;

	cout << "Введите количество нод: ";
	cin >> list_size;

	if (list_size == 1)
	{
		cout << "Введите значение ноды #1: ";
		cin >> inp_data;

		create_node(inp_data); // вызвать функцию #1
	} 
	else 
	{
		for (int i = 0; i != list_size; i++)
		{
			cout << "Введите значение ноды #" << i + 1 << ": ";
			cin >> inp_data;

			t_list* p;
			p = create_node(inp_data); // вызвать функцию #1
			push_node(&p, p);
		}
	}
}









// *************************************
// ***********LVL 4 POINTERS************
// *************************************
//int example()
//{
//	int* p_var; // создание указателя
//	p_var = new int; // int - значит 4 байта и какого типа указатель возвращать
//	cout << *p_var << endl;
//	*p_var = 1488;
//	cout << *p_var << endl;
//	cout << "adress: " << p_var << endl;
//
//	delete p_var; // вызов когда закончили работать с данными, 
//
//	const int size = 10;
//	p_var = new int[10]; // выделение памяти
//	cout << "adress: " << p_var << endl;
//
//	for (int i = 0; i < size; i++)
//		cout << *p_var++ << ' '; // прогон по адресам выделенные под p_var
//	for (int i = size - 1; i >= 0; i--)
//		cout << *--p_var << ' ';
//	cout << endl;
//
//	delete[] p_var; // после выделения с new - удалить выделенную память
//
//	return(0);
//}