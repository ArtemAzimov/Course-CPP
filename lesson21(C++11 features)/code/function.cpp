#include <iostream>
#include <functional>

void foo(int arg1, int arg2) {

}

int add(int a, int b) {
  return a + b;
}

// Пример функционального объекта
struct Multiply {
  int operator()(int a, int b) const {
    return a * b;
  }
};

#include <vector>

using TFunc = std::function<int(int, int)>;

int main() {
  // std::function<int(int, int)> func;  // Объявление std::function для функций с сигнатурой int(int, int)

  auto f = add;
  std::cout << f(3,4);

  std::vector<TFunc> vFunc;

  Multiply multiply;  // Создание экземпляра функционального объекта

  vFunc.push_back(multiply);  // Присваивание функционального объекта
  vFunc.push_back(add);

  int result = vFunc[0](3, 4);  // Вызов хранимой функции
  std::cout << "Multiply: " << result << std::endl;  // Вывод результата (6)
  result = vFunc[1](3,4);
  std::cout << "Sum: " << result << std::endl;  // Вывод результата (6)

  return 0;
}
