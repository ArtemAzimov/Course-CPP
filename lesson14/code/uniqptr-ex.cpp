// Unique Pointer Example

#include <iostream>
#include <memory>

class TestClass{
    private:
        int value;

    public:
        TestClass(int number){
            value = number;
            std::cout<<"Created Object: "<<value<<std::endl;
        }

        ~TestClass(){
            std::cout<<"Destroyed Object: "<<value<<std::endl;
        }

        void display(){
            std::cout<<"Value: "<<value<<std::endl;
        }
};

int main(){

    // Create a unique pointer to TestClass object
    std::unique_ptr<TestClass> ptr(new TestClass(1));

    // Access object using pointer
    ptr->display();

    // Create another unique pointer and transfer ownership
    std::unique_ptr<TestClass> ptr2 = std::move(ptr);

    // Nullify original pointer
    ptr = nullptr;

    // Access object using moved pointer
    ptr2->display();

    // Unique pointer gets deleted when out of scope
    std::cout<<"End of function"<<std::endl;

    return 0;
}