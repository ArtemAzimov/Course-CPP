#include <iostream>
#include <vector>

class MyClass {
public:
  int* data;

  // Конструктор
  MyClass(int value) {
    data = new int(value);
    std::cout << "Constructor: " << *data << std::endl;
  }

  // Move-конструктор
  MyClass(MyClass&& other) noexcept {
    data = other.data;
    other.data = nullptr;
    std::cout << "Move Constructor: " << *data << std::endl;
  }

//   // Move-оператор присваивания
  MyClass& operator=(MyClass&& other) noexcept {
    if (this != &other) {
      delete data;
      data = other.data;
      other.data = nullptr;
    }
    std::cout << "Move Assignment Operator: " << *data << std::endl;
    return *this;
  }

    MyClass(const MyClass& other){
        std::cout << "Assignment Constructor: " << *data << std::endl;
        this->data = new int(*other.data);
    }

  MyClass& operator=(const MyClass& other)  {
    std::cout << "Assignment Operator: " << *data << std::endl;
    this->data = new int(*other.data);
    return *this; 
  }

  // Деструктор
  ~MyClass() {
    delete data;
    std::cout << "Destructor" << std::endl;
  }
};

int main() {
  MyClass obj1(42);
  MyClass obj2 = std::move(obj1);
//   MyClass obj2 = static_cast<MyClass&&>(obj1);
//   MyClass obj2 = obj1;
  if (obj1.data == nullptr) {
    std::cout << "obj1.data is null" << std::endl;
  }
  std::cout << "obj2.data " << *obj2.data << std::endl;
//   std::vector<MyClass> myClasses;
//   obj1 = obj2;
// for (size_t i = 0; i < 6; i++)
// {
//     MyClass temp(i);
//     myClasses.push_back(temp);
// }



  return 0;
}