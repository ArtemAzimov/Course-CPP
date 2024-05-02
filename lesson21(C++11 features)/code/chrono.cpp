#include <iostream>
#include <chrono>

int main() {
    // Получение текущего времени
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();

    // Создание точки времени с заданной датой и временем
    std::chrono::system_clock::time_point customTime = std::chrono::system_clock::from_time_t(0); // Начало эпохи

    // Вычисление разницы между двумя точками времени
    std::chrono::duration<double> timeDiff = currentTime - customTime;
    std::cout << "Прошло " << timeDiff.count() << " секунд с начала эпохи." << std::endl;

    // Преобразование длительности в другую единицу измерения
    std::chrono::duration<double, std::ratio<60>> minutes = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<60>>>(timeDiff);
    std::cout << "Прошло " << minutes.count() << " минут с начала эпохи." << std::endl;

    // Использование steady_clock для измерения времени выполнения кода
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    // Код, время выполнения которого мы хотим измерить
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Вычисление времени выполнения
    std::chrono::duration<double> elapsedTime = end - start;
    std::cout << "Время выполнения кода: " << elapsedTime.count() << " секунд." << std::endl;

    return 0;
}
