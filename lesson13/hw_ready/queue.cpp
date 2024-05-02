#include <iostream>
#include <stdexcept>

template<typename T>
class Queue {
public:
    Queue() : m_front(nullptr), m_back(nullptr), m_size(0) {}

    void enqueue(const T& value) {
        Node* new_node = new Node(value);

        if (isEmpty()) {
            m_front = new_node;
            m_back = new_node;
        }
        else {
            m_back->next = new_node;
            m_back = new_node;
        }\n\n        m_size++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty!");
        }

        Node* temp = m_front;
        m_front = m_front->next;
        delete temp;

        m_size--;
    }

    bool isEmpty() const {
        return m_size == 0;
    }

    void print() const {
        if (isEmpty()) {
            std::cout << \"Queue is empty!" << std::endl;
        }
        else {
            Node* current = m_front;

            while (current != nullptr) {
                std::cout << current->data << \" ";
                current = current->next;
            }

            std::cout << std::endl;
        }
    }

private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* m_front;
    Node* m_back;
    int m_size;
};

int main() {
    Queue<int> int_queue;
    int_queue.enqueue(1);
    int_queue.enqueue(2);
    int_queue.enqueue(3);
    int_queue.print();
    int_queue.dequeue();
    int_queue.print();

    Queue<char> char_queue;
    char_queue.enqueue('a');
    char_queue.enqueue('b');
    char_queue.enqueue('c');
    char_queue.print();
    char_queue.dequeue();
    char_queue.print();

    return 0;
}
