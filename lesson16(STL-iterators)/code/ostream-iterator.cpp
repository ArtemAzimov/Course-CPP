#include <iostream>
#include <vector>
#include <iterator>  // для std::ostream_iterator
#include <fstream>

int main() {
    // Создание вектора и заполнение его значениями
    std::vector<int> v{5, 2, 8, 3, 1};
    std::fstream f("output.txt");

    // Использование ostream_iterator для вывода содержимого вектора на экран
    // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " - "));
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(f, " - "));
    std::cout << std::endl;

    return 0;
}