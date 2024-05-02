#pragma once

#include <iostream>

// last in first out
template<typename T>
class custom_Queue
{
private:
    struct Node{
        T _data;
        Node* _next;
        Node* _prev;
        Node(const T& data) : _data(data), _prev(nullptr), _next(nullptr) {}
    };

    Node* _head;
    Node* _last;
    Node* _end;
    unsigned int _size;
public: 
    custom_Queue() : _head(nullptr), _last(nullptr), _end(nullptr), _size(0) {}
    ~custom_Queue(){}

    void add(const T& data){
        Node* new_node = new Node(data);
        if (_size == 0){
            _head = new_node;
            _last = _head;
            _size++;
        }
        else {
            _last->_next = new_node;
            new_node->_prev = _last;
            _last = new_node;
            _size++;
        }
    }

    void remove(){
        Node* temp = _head;
        _head = _head->_next;
        _head->_prev = nullptr;
        delete temp;
        _size--;
        std::cout << "REMOVED ELEMENT" << std::endl;
    }

    unsigned int getSize() const{
        return _size;
    }

    void show(){
        std::cout << std::endl << "SHOW METHOD WITHOUT ITERATORS" << std::endl;
        Node* pointer;
        pointer = _last;
        while (pointer != nullptr){
            std::cout << pointer->_data << std::endl;
            pointer = pointer->_prev;
        }
        std::cout << std::endl;
    }


    class custom_QueueIterator{
    private:
        Node* _pointer;
    public:
        custom_QueueIterator () : _pointer(nullptr) {}
        custom_QueueIterator (Node* pointer) : _pointer(pointer) {}

        T& operator * () { return _pointer->_data; }
        T operator -> () { return &(_pointer->_data); }
        bool operator == (const custom_QueueIterator& other) { return _pointer == other._pointer; }
        bool operator != (const custom_QueueIterator& other) { return _pointer != other._pointer; }

        // префикс
        custom_QueueIterator& operator ++ () {
            _pointer = _pointer->_next;
            return *this;
        }

        // постфикс
        custom_QueueIterator operator ++ (T) {
            custom_QueueIterator temp = *this;
            _pointer = _pointer->_next;
            return temp;
        }
    };

    custom_QueueIterator begin() { return custom_QueueIterator (_head); }
    custom_QueueIterator end() { return custom_QueueIterator (_last->_next); }


    /*
        NEW FEATURES
    */

    // Добавил реверс-итератор
    class custom_QueueIterator_Reverse{
    private:
        Node* _pointer;
    public:
        custom_QueueIterator_Reverse () : _pointer(nullptr) {}
        custom_QueueIterator_Reverse (Node* pointer) : _pointer(pointer) {}

        bool operator != (const custom_QueueIterator_Reverse& other) { return _pointer != other._pointer; }
        T& operator * () { return _pointer->_data; }

        // префикс
        custom_QueueIterator_Reverse& operator ++ () {
            _pointer = _pointer->_prev;
            return *this;
        }
    };

    // Добавил методы для вызова ревер-итератора
    custom_QueueIterator_Reverse rbegin() { return custom_QueueIterator_Reverse (_last); }
    custom_QueueIterator_Reverse rend () { return custom_QueueIterator_Reverse (_head->_prev); }
};

