#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  // использование алгоритмов STL для работы с vector
  std::vector<int> v = {3, 2, 1, 4, 5};
  std::sort(v.begin(), v.end());
  std::cout << "Сортировка: ";
  for (auto i : v) std::cout << i << " ";
  std::cout << std::endl;

  int n = 3;
  bool result = std::binary_search(v.begin(), v.end(), n);
  std::cout << "Бинарный поиск " << ": " << (result ? "найден" : "не найден") << std::endl;

  // использование алгоритмов STL для работы с массивами
  int arr[] = {3, 2, 1, 4, 5};
  std::sort(arr, arr + 5);
  std::cout << "Сортировка: ";
  for (auto i : arr) std::cout << i << " ";
  std::cout << std::endl;

  int* p = std::find(arr, arr + 5, 3);
  std::cout << "Поиск указателя на 3: " << (p != arr + 5 ? std::to_string(*p) : "не найден") << std::endl;

  // использование алгоритмов STL для работы с указателями
  int* arrp[5];
  for (int i = 0; i < 5; i++) arrp[i] = &arr[i];

  std::sort(arrp, arrp + 5, [](int* a, int* b){ return *a > *b; });
  std::cout << "Сортировка указателей: ";
  for (int i = 0; i < 5; i++) std::cout << *arrp[i] << " ";
  std::cout << std::endl;

  return 0;
}