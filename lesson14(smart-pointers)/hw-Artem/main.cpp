#include "tcSmartPointer.hpp"

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