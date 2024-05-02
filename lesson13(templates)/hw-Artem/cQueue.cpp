#include <iostream>

using std::cout;
using std::endl;

template<typename T>    // Обязательно объявление объекта класса с аргументом, т.к. он должен определить typename.
class Queue 
{
private:
    T _data;
    Queue* _next;
    bool _del;
public:
    Queue(const T data = 0)
    {
        _data = data;
        _next = nullptr;
        _del = false;
    }
    ~Queue()
    {
        cout << ".......called ~Queue destructor" << endl;
    }

	void enqueue(const T data)
	{
        Queue* elem = this;
        while (elem->_next != nullptr)
        {
            elem = elem->_next;
        }
        elem->_next = new Queue;
        elem->_next->_data = data;
    }

    void dequeue()
    {
        Queue* p = this;

        if (p->_del == false)
        {
            p->_del = true;
        }
        else
        {
            while (p->_del != false)
            {
                p = p->_next;
            }
            p->_del = true;
        }
        
        cout << ".......called dequeue" << endl;
    }

    void isEmpty()
    {
        Queue* p = this;
        while (p->_next != nullptr)
        {
            p = p->_next;
        }
        if (p->_del == false)
        {
            cout << "Queue is NOT empty" << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }

    void print()
    {
        cout << endl << ".......Current queue:" << endl;

        Queue* p = this;

        while (p->_next != nullptr)
        {
            if (p->_del == false)
            {
                cout << '[' << p->_data << ']' << '\t';
            }
            p = p->_next;
        }
        if (p->_del == false)
        {
            cout << '[' << p->_data << ']' << '\t' << endl;
        }
    }
};


int main()
{
    Queue test{1};
    test.enqueue(2);
    test.enqueue(55);
    test.enqueue(778);
    test.print();

    test.dequeue();
    test.dequeue();
    test.dequeue();
    test.print();
    test.isEmpty();

    test.dequeue();
    test.print();
    test.isEmpty();

    return 0;
}