#include <iostream>

int main() {
    int x = 5;
    
    x += 10;
    
    if (x > 15) {
        std::cout << "x больше 15" << std::endl;
    }
    else {
        std::cout << "x меньше или равно 15" << std::endl;
    }
    
    return 0;
}