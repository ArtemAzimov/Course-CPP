#include <iostream>

using namespace std;

struct t_list
{
	int     data;
	t_list* next;
};

t_list* create_node(int data)
{
	t_list* ret = new t_list;
	ret->data = data;         // -> разыменовывает указатель
	ret->next = nullptr;      // то есть, это то же самое, что и (*ret)

	return ret;
}

void push_node(t_list** head, t_list* node)
{
	if (head == nullptr || *head == nullptr) // Проверяем, не скинули ли нам указатель на nullptr или сам nullptr
		return ;

	t_list* iterator = *head;           // Сам head типа t_list**, поэтому разыменовав его получаем t_list*
	while ( iterator->next != nullptr ) // Идем до конца списка
	{
		iterator = iterator->next;
	}

	iterator->next = node; // Прицепляем в конец списка нашу новую ноду
}

void show_list(t_list* head)
{
	if ( head == nullptr )
		return ;

	for (; head->next != nullptr; head = head->next)
	{
		cout << head->data << '\t';
	}
	cout << head->data << endl; // Оператором "стрелка" удобнее разыменовывать указатели на указатель на ука...
}

int main()
{
	const int list_size = 10;
	t_list*   list = create_node(0);

	for (int i = 1; i < list_size; i++)
	{
		t_list* new_node = create_node(i);
		push_node(&list, new_node);
	}
	show_list(list);
}

