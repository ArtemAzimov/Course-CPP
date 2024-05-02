#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> vec = {1, -2, 3, 4, 5};
    std::transform(vec.begin(), vec.end(), vec.begin(), std::negate());
    for (int i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}