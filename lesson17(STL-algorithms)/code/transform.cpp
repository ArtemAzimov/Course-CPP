#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  std::vector<int> v = {3, 5, 2, 8, 1, 6};
  std::vector<int> v2(v.size());

  // применение операции к каждому элементу и сохранение результата
  std::transform(v.begin(), v.end(), v2.begin(), [](int x) { return x * x; });

  // вывод нового вектора
  for (int i : v2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}