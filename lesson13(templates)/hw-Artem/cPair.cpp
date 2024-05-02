#include <iostream>
#include <string>

using std::cout;

template<typename T>        // принимает только одинаковые типы. Если char [], то одинаковой длины.
class Pair
{
private:
    T first, second;
public:
    Pair(const T& first, const T& second){}

    void setFirst(T first)
    {
        this->first = first;
    }

    void setSecond(T second)
    {
        this->second = second;
    }

    T getFirst()
    {
        return first;
    }

    T getSecond()
    {
        return second;
    }

    void show()
    {
        cout << ".......OUTPUT: " << getFirst() << ", " << getSecond() << std::endl;
    }
};

int main()
{
    Pair test1{4314, 543};

    test1.show();

    Pair test2{"str", "stt"};

    return 0;
}