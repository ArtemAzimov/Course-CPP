#include <iostream>

// Function that takes a const lvalue reference
void printValue(const int& value) {
    std::cout << "Value: " << value << std::endl;
}

// Function that takes an rvalue reference
void processValue(int&& value) {
    value *= 2;
    std::cout << "Processed value: " << value << std::endl;
}

int main() {
    int x = 10;

    // Using const lvalue reference
    printValue(x); // Passes x by const lvalue reference

    // Using rvalue reference
    processValue(42); // Passes 42 as an rvalue reference

    return 0;
}
