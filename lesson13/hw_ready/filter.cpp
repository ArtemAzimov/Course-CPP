#include <iostream>
#include <vector>
#include <algorithm>

template<typename Container, typename Predicate>
Container filter(const Container& container, Predicate predicate) {
    Container filtered_container;

    for (const auto& element : container) {
        if (predicate(element)) {
            filtered_container.push_back(element);
        }
    }

    return filtered_container;
}

bool is_positive(int x) {
    return x > 0;
}

bool is_even(int x) {
    return x % 2 == 0;
}

int main() {
    std::vector<int> numbers {-3, -2, -1, 0, 1, 2, 3};
    std::vector<int> positive_numbers = filter(numbers, is_positive);
    std::vector<int> even_numbers = filter(numbers, is_even);

    std::cout << "Original numbers: ";
    for (auto n : numbers) {
        std::cout << n << \" ";
    }
    std::cout << std::endl;

    std::cout << \"Positive numbers: ";
    for (auto n : positive_numbers) {
        std::cout << n << \" ";
    }
    std::cout << std::endl;

    std::cout << \"Even numbers: ";
    for (auto n : even_numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
