/*  
    Реализация своего собственного контейнера с использованием итераторов. 
    Например, можно реализовать простой стек или очередь с использованием итераторов, 
    чтобы показать, как работают различные типы итераторов и как их можно использовать 
    для перебора элементов контейнера.
*/
#pragma once

#include <iostream>

// last in last out
template<typename T>
class custom_Stack{
private:
    struct Node{
        T _data;
        Node* _next;
        Node (const T& data) : _data(data), _next(nullptr){}
    };
public:
    Node* _head;

    custom_Stack() : _head(nullptr) {}
    ~custom_Stack(){}

    void add(T data){
        Node* newnode = new Node(data);
        if (_head == nullptr){
            _head = newnode;
        }
        else{
            Node* temp = _head;
            _head = newnode;
            newnode->_next = temp;
        }
    }

    void remove()
    {
        if (_head != nullptr){
            Node* temp = _head;
            _head = _head->_next;
            temp = nullptr;
            delete temp;
        }
    }

    void show()
    {
        std::cout << _head->_data << std::endl;
    }
};