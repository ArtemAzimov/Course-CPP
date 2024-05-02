/*  
    Реализация своего собственного контейнера с использованием итераторов. 
    Например, можно реализовать простой стек или очередь с использованием итераторов, 
    чтобы показать, как работают различные типы итераторов и как их можно использовать 
    для перебора элементов контейнера.
*/

#include <iostream>

// last in first out
template<typename T>
class Stack
{
private:
    struct Process
    {
        T _data;
        Process* _next;
        Process* _prev;
        Process(const T& data) : _data(data), _prev(nullptr), _next(nullptr) {}
    };

    Process* _head;
    Process* _last;
    Process* _end;
    unsigned int _size;
public: 
    Stack() : _head(nullptr), _last(nullptr), _end(nullptr), _size(0) {}
    ~Stack(){}

    void add(const T& data){
        Process* newproc = new Process(data);
        if (_size == 0){
            _head = newproc;
            _last = _head;
            _size++;
        }
        else {
            _last->_next = newproc;
            newproc->_prev = _last;
            _last = newproc;
            _size++;
        }
    }

    void remove(){
        Process* temp = _head;
        _head = _head->_next;
        _head->_prev = nullptr;
        delete temp;
        _size--;
    }

    unsigned int getSize() const{
        return _size;
    }

    void show(){
        std::cout << std::endl << "SHOW METHOD WITHOUT ITERATORS" << std::endl;
        Process* pointer;
        pointer = _last;
        while (pointer != nullptr){
            std::cout << pointer->_data << std::endl;
            pointer = pointer->_prev;
        }
        std::cout << std::endl;
    }


    class StackIterator
    {
    private:
        Process* _pointer;
    public:
        StackIterator () : _pointer(nullptr) {}

        StackIterator (Process* pointer) : _pointer(pointer) {}

        T& operator * () { return _pointer->_data; }
        T operator -> () { return &(_pointer->_data); }
        bool operator == (const StackIterator& other) { return _pointer == other._pointer; }
        bool operator != (const StackIterator& other) { return _pointer != other._pointer; }

        // префикс
        StackIterator& operator ++ () {
            _pointer = _pointer->_next;
            return *this;
        }

        // постфикс
        StackIterator operator ++ (T) {
            StackIterator temp = *this;
            _pointer = _pointer->_next;
            return temp;
        }
    };

    StackIterator begin() { return StackIterator (_head); }
    StackIterator end() { return StackIterator (_last->_next); }
    // StackIterator rbegin() { return StackIterator (_last); }
    // StackIterator rend() { return StackIterator (_head); }
};