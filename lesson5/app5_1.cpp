#include <iostream>

using namespace std;

struct t_list
{
	int     data;
	t_list* next = nullptr; // ИНИЦИАЛИЗАЦИЯ ТЕПЕРЬ ЗДЕСЬ
};

t_list* create_node(int data)
{
	t_list* ret = 0; // создание пустого указателя типа структура Лист
	ret = new t_list; // выделение динамической памяти для структуры Лист и присвоение указателя на адрес памяти
	cout << "ret....." << ret << endl;
	ret->data = data;         // присвоить данные Ноды в поле данные структуры Лист по указателю
	cout << "ret->data....." << ret->data << endl;
	ret->next;      // ПРОСТО ИНИЦИАЛИЗАЦИЯ, присвоить хед-Ноде указатель на следующую Ноду = нулпоинтер
	cout << "ret.data....." << (*ret).data << endl;
	cout << "ret.next....." << (*ret).next << endl;

	return ret; // возвращает указатель (адрес памяти t_list)
}

void push_node(t_list** head, t_list* node) // принять указатель на указатель адреса памяти указателя хед-Ноды, принять указатель на новую-Ноду
{
	if (head == nullptr || *head == nullptr) // Проверяем, не скинули ли нам указатель равный nullptr или указатель, указыювающий на nullptr
		return;

										// head - это адрес указателя на хед-Ноду
										// push_node приняла указатель на указатель на адрес указателя на хед-Ноду
	t_list* iterator = *head;           // ** head = &list, чтобы получить указатель на адрес хед-Ноды разыменовываем указатель head путем *head
	while (iterator->next != nullptr)	// пока поле next хед-Ноды не равно 0 - присвоить iterator адрес новой-Ноды из поля next хед-Ноды
	{
		iterator = iterator->next;
	}
							// присвоить iterator адрес новой-Ноды из поля некст переданной Ноды
	iterator->next = node; // Прицепляем в конец списка нашу новую ноду
	cout << "push_node iterator->next....." << iterator->next << endl << endl;;
}

void show_list(t_list* head)
{
	if (head == nullptr)
		return;

	for (; head->next != nullptr; head = head->next) // для каждого элемента, пока указатель новой-Ноды != nullptr - текущая нода = указатель следующая нода
	{
		cout << head->data << '\t'; // вывести данные текущей ноды
	}
	cout << head->data << endl; // Оператором "стрелка" удобнее разыменовывать указатели на указатель на ука...
}

int main()
{
	const int list_size = 3;
	t_list* list = create_node(0); // создать указатель типа структуры Лист на указатель адреса памяти хед-Ноды !!!СОХРАНИЛИ АДРЕС В ПАМЯТИ ХЕД-НОДЫ

	for (int i = 1; i < list_size; i++) // прогнать по всем элементам листа (list_size)
	{
		t_list* new_node = create_node(i); // создать указатель типа структуры Лист на указатель адреса памяти новой-Ноды
		push_node(&list, new_node); // передать адрес памяти указателя на указатель адреса памяти хед-Ноды, указатель адреса памяти новой-Ноды
	}
	show_list(list);
}

