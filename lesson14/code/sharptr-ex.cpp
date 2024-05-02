#include <iostream>

int main() {
    std::shared_ptr mySharedPtr(new int(42));
    std::cout << *mySharedPtr << std::endl;
    {
        std::shared_ptr<int> myOtherSharedPtr = mySharedPtr;
    std::cout << *myOtherSharedPtr << std::endl;
}

std::cout << *mySharedPtr << std::endl;

return 0;

}

