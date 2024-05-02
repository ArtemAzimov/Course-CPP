#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> mySharedPtr(new int(42));
    std::cout << *mySharedPtr << " " << mySharedPtr.use_count() << std::endl;
    {
        std::shared_ptr<int> myOtherSharedPtr = mySharedPtr;
        std::cout << *mySharedPtr << " " << mySharedPtr.use_count() << std::endl;
        {
            std::shared_ptr<int> myOtherSharedPtr = mySharedPtr;
            std::cout << *mySharedPtr << " " << mySharedPtr.use_count() << std::endl;
        }
        std::cout << *mySharedPtr << " " << mySharedPtr.use_count() << std::endl;
    }

    std::cout << *mySharedPtr << " " << mySharedPtr.use_count() << std::endl;

    return 0;
}
