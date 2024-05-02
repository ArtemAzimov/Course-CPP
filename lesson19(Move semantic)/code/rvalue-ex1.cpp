#include <iostream>
#include <vector>

// Пример класса с дорогостоящими ресурсами
class MyResource {
public:
    MyResource() {
        std::cout << "Выделение ресурса" << std::endl;
    }

    ~MyResource() {
        std::cout << "Освобождение ресурса" << std::endl;
    }
};

// Функция, принимающая rvalue-ссылку на объект MyResource
void processResource(MyResource&& resource) {
    // Используем ресурс
    std::cout << "Обработка ресурса" << std::endl;
}

int main() {
    // Создание временного объекта MyResource
    processResource(MyResource());

    return 0;
}
