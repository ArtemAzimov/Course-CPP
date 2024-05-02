#include <iostream>
#include <vector>

int main()
{
    // Initialize a vector of integers
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Add elements to the vector
    vec.push_back(6);
    vec.push_back(7);

    // Print the vector elements
    std::cout << "Vector elements:" << std::endl;
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Erase an element from the vector
    vec.erase(vec.begin() + 3);

    // Print the vector elements again
    std::cout << "Vector elements after erasing the element at index 3:" << std::endl;
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
