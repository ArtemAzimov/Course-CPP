#include <unordered_map>
#include <iostream>
#include <string>

template<typename T>
T max(const T& a, const T& b) {
    return a > b ? a : b;
}

template<typename T, typename... Args>
T max(const T& a, const T& b, const Args&... args) {
    return max(max(a, b), args...);
}

int main() {
    std::cout << "Max of 1 and 2: " << max(1, 2) << std::endl;
    std::cout << "Max of 1.5, 3.5, and -1.0: " << max(1.5, 3.5, -1.0) << std::endl;
    std::cout << "Max of 'a', 'z', and 'c': " << max('a', 'z', 'c') << std::endl;
    std::cout << "Max of true, false, and true: " << max(true, false, true) << std::endl;
    std::cout << "Max of std::string(\"hello\"), std::string(\"world\"), and std::string(\"foo\"): " << max(std::string("hello"), std::string("world"), std::string("foo")) << std::endl;
    std::cout << "Max of 1, 2, 3, and 4: " << max(1, 2, 3, 4) << std::endl;

    return 0;
}
