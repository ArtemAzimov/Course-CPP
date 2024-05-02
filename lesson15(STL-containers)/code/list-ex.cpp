#include <iostream>
#include <list>

int main()
{
    std::list<int> numbers = {1, 2, 3, 4, 5};

    // Output the list
    std::cout << "Initial list: ";
    for (auto i : numbers)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Add a new number to the beginning of the list
    numbers.push_front(0);

    // Remove the last number from the list
    numbers.pop_back();

    // Replace the second number in the list with a new value
    auto it = numbers.begin();
    std::advance(it, 1);
    *it = 10;

    // Output the modified list
    std::cout << "Modified list: ";
    for (auto i : numbers)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
