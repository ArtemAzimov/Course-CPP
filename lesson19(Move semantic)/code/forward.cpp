#include <iostream>
#include <utility>

void processResource(int&& resource) {
  // Обработка ресурса
  std::cout << "Processing resource: " << resource << std::endl;
}

template <typename T>
void process(T&& value) {
  // Общая обработка значения
  processResource(std::forward<T>(value)); // Передача значения без изменения категории
}

int main() {
  int resource = 42;

  process(std::move(resource)); // Перемещение ресурса

  return 0;
}