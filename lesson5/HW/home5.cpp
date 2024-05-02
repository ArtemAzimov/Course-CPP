#include <iostream>

using namespace std;

class MyList
{
protected:
    int _data;
    MyList* _next;
public:
	MyList(int data = 0, MyList* next = nullptr)
	{
        _data = data;
        _next = next;
	}
	~MyList() {}

	MyList* createNode(int data) // функция возвращает указатель на Ноду
	{
        MyList* head_node = new MyList;
        head_node->_data = data;
        return head_node;
	}

	void pushNode(MyList* new_node)
	{
        MyList* iterator = this; // указатель на того кто вызвал
        for (; iterator->_next != nullptr; /* iterator++ */ iterator = iterator->_next);
        iterator->_next = new_node;
	}

	void showList()
	{
        MyList* it = _next;
        for (; it != nullptr; /* it++ */ it = it->_next)
        {
            cout << it->getData() << '\t'; // лучше использовать геттер (проверка или валидация данных)
        }
	}

	int getData() // метод getter, который возвращает данные
	{
        return _data;
    }
};

int main()
{
    MyList head;

    int list_size = 10;

    for (int i = 1; i != list_size + 1; i++) 
    {
        MyList* new_node = head.createNode(i);
        head.pushNode(new_node);
    }
    head.showList();
}