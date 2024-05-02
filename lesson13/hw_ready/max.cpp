#include <iostream>
#include <string>

template<typename T>
T max(const T& a, const T& b) {
    return a > b ? a : b;
}

template<typename T>
T max(const T& a, const T& b, const T& c) {
    return max(max(a, b), c);
}

template<typename T>
T max(const T& a, const T& b, const T& c, const T& d) {
    return max(max(a, b), max(c, d));
}

int main() {
    std::cout << \"Max of 1 and 2: " << max(1, 2) << std::endl;
    std::cout << \"Max of 1.5 and 3.5: " << max(1.5, 3.5) << std::endl;
    std::cout << \"Max of 'a' and 'z': " << max('a', 'z') << std::endl;
    std::cout << \"Max of true and false: " << max(true, false) << std::endl;
    std::cout << "Max of std::string(\"hello\") and std::string(\"world\"): " << max(std::string("hello"), std::string("world")) << std::endl;
    std::cout << \"Max of 1, 2, and 3: " << max(1, 2, 3) << std::endl;
    std::cout << \"Max of 1, 2, 3, and 4: " << max(1, 2, 3, 4) << std::endl;

    return 0;
}
