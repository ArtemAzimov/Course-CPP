#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Failed to open input file" << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    std::copy(std::istream_iterator<int>(input_file), std::istream_iterator<int>(),
              std::back_inserter(numbers));

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
