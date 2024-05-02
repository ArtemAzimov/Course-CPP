#include "2_my_container.hpp"
#include <stack>

int main()
{
    Stack<int> test;
    test.add(5);
    test.add(842);
    test.add(555);
    test.add(1030);
    test.show();
    test.remove();
    test.show();
    std::cout << "Size = " << test.getSize() << std::endl;

    


    std::cout << std::endl << "SHOW METHOD WITH CLASS ITERATOR (FORWARD)" << std::endl;
    for (auto it = test.begin(); it != test.end(); ++it){
        std::cout << *it << std::endl;
    }

    // std::cout << std::endl << "SHOW METHOD WITH CLASS ITERATOR (REVERSE)" << std::endl;
    // for (auto it = test.rbegin(); it != test.rend(); ++it){
    // std::cout << *it << std::endl;
    // }



    return 0;
}