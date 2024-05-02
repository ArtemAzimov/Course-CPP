#include <iostream>

using namespace std;

struct list_node
{
	int data = 0;
	list_node* next = nullptr;
};

void listing(list_node node)
{
	for (node; node.next != nullptr; node = *(node.next))
		cout << node.data << "       " << node.next << '\n';
	cout << node.data << '\n'; // вывести текущий не отработанный
}

int main()
{
	list_node node0;
	list_node node1;
	list_node node2;
	list_node node3;
	list_node node4;
	list_node node5;
	list_node node6;

	node0.data = 1;
	node0.next = &node1;

	node1.data = 2;
	node1.next = &node2;

	node2.data = 3;
	node2.next = &node3;

	node3.data = 4;
	node3.next = &node4;

	node4.data = 5;
	node4.next = &node5;

	node5.data = 6;

	node6.data = 7;

	listing(node0);
}