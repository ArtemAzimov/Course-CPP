/*  
2.  Реализация своего собственного контейнера с использованием итераторов. 
    Например, можно реализовать простой стек или очередь с использованием итераторов, 
    чтобы показать, как работают различные типы итераторов и как их можно использовать 
    для перебора элементов контейнера.
*/

#include "2_custom_Queue.hpp"
#include "2_custom_Stack.hpp"

int main()
{
//*********QUEUE**********
    std::cout << std::endl << "//*********QUEUE**********" << std::endl;
    custom_Queue<int> testQueue;
    testQueue.add(5);
    testQueue.add(842);
    testQueue.add(555);
    testQueue.add(1030);
    testQueue.show();
    testQueue.remove();
    testQueue.show();
    std::cout << "Size = " << testQueue.getSize() << std::endl;

    std::cout << std::endl << "SHOW METHOD WITH CLASS ITERATOR (FORWARD)" << std::endl;
    for (auto it = testQueue.begin(); it != testQueue.end(); ++it){
        std::cout << *it << std::endl;
    }


//*********STACK**********
std::cout << std::endl << "//*********STACK**********" << std::endl;
    custom_Stack<int> testStack;
    testStack.add(100);
    testStack.add(222);
    testStack.add(395);
    testStack.show();
    testStack.remove();
    testStack.show();
    testStack.add(999);
    testStack.show();


    return 0;
}