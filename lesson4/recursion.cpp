#include <iostream>

using namespace std;

struct t_list
{
	int     data;
	t_list* next;
};

void output_data(t_list* list) // Рекурсивная функция
{
	if (list == nullptr) // Базовый случай
	{
		cout << '\n';
		return ;
	}
	
	cout << '\t' << list->data;
	output_data(list->next); // Рекурсивный вызов
}

int main()
{
	t_list node1;
	t_list node2;
	t_list node3;
	t_list node4;
	t_list node5;

	node1.data = 1;
	node1.next = &node2;
	node2.data = 2;
	node2.next = &node3;
	node3.data = 3;
	node3.next = &node4;
	node4.data = 4;
	node4.next = &node5;
	node5.data = 5;
	node5.next = nullptr;

	output_data(&node1);

	// ************** DYNAMICLY ALLOCATED LIST ***************** //

	// const int list_size = 5;
	// t_list*   list_start = new t_list;

	// t_list* node = list_start;
	// for (int i = 0; i < list_size; ++i)
	// {
	// 	node->data = i;
	// 	node->next = new t_list;
	// 	node = node->next;
	// }
	// node->data = list_size;
	// node->next = nullptr;

	// output_data(list_start);

	// for (t_list* node = list_start; node != nullptr; node = node->next)
	// {
	// 	t_list* to_delete = node;
	// 	node = node->next;
	// 	delete to_delete;
	// }

	return (0);
}