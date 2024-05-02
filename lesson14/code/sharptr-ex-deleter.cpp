#include <iostream>
#include <fstream>
#include <memory>

int main () {
  // Открытие файла для записи\n  std::ofstream outputFile("example.txt");

  // Создание shared_ptr с пользовательским удалятором
  std::shared_ptr<std::ofstream> outputFilePtr(&outputFile, [](std::ofstream* ptr) {
    std::cout << \"Закрываем файл...\n";
    ptr->close();
  });

  // Запись в файл
  (*outputFilePtr) << \"Это пример использования shared_ptr с пользовательским удалятором.\n";

  // outputFile и outputFilePtr уничтожаются в конце области видимости
  return 0;
}
