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

    // std::copy(numbers.rbegin() + 1, numbers.rend(), std::ostream_iterator<int>(std::cout, "::"));

    for (auto it=numbers.begin(); it!=numbers.end(); it++) {
    // for (auto it: numbers) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
