#include <iostream>

using std::cout; using std::endl; using std::cerr;


template<typename T>
class SmartPointer
{
private:
    T* value;
    int count;
public:
    SmartPointer(T* value = nullptr) : value(value)
    {
        if (value != nullptr)
        {
            count = 1;
        }
        else count = 0;
    }

    SmartPointer(const SmartPointer<T>& newptr)     // конструктор копирования для sharedptr
    {
        value = newptr.value;
        count = newptr.count;
        if(value != nullptr) 
        {
            count++;        // если поинтер не нулевой то увеличить счетчик ссылок
        }
    }

    ~SmartPointer()     // деструктор с проверкой на кол-во ссылок
    {
        if(value != nullptr)
        {
            count--;
            if(count == 0) 
            {
                delete value;       // тут ошибка
            }
        }
    }

    int counter() const     // имя члена-переменной класса != имя метода класса (count count)
    {
        return count;
    }

    void reset()
    {

    }

};

int main()
{
    int a = 777;
    int* rawptr = &a;

    SmartPointer ptr0{rawptr};
    cout << ptr0.counter() << endl;

    SmartPointer ptr1{ptr0};
    cout << ptr0.counter() << endl;
    cout << ptr1.counter() << endl;
    

    

    return 0;
}