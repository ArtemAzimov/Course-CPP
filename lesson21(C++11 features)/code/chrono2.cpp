#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Измерение времени выполнения кода
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    // Задержка выполнения на 1 секунду
    // std::this_thread::sleep_for(std::chrono::seconds(3));

    // Измерение времени после задержки
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // Вычисление времени выполнения
    std::chrono::duration<double> elapsedTime = end - start;
    std::cout << "Время выполнения: " << elapsedTime.count() << " секунд." << std::endl;
    std::cout << "Время выполнения: " << std::chrono::duration_cast<std::chrono::nanoseconds>(start - end).count() << " секунд." << std::endl;

    // Получение текущего времени
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    std::cout << "Текущее время: " << std::ctime(&currentTime_t);

    // Использование high_resolution_clock для измерения точного времени
    auto startHR = std::chrono::high_resolution_clock::now();
    // Код, время выполнения которого мы хотим измерить
    auto endHR = std::chrono::high_resolution_clock::now();

    // Вычисление времени выполнения с высоким разрешением
    auto elapsedTimeHR = std::chrono::duration_cast<std::chrono::nanoseconds>(endHR - startHR).count();
    std::cout << "Время выполнения с высоким разрешением: " << elapsedTimeHR << " наносекунд." << std::endl;

    return 0;
}
