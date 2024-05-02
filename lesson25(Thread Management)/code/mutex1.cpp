#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mutex1, mutex2;
int sharedData = 0;
int sharedData2 = 0;

void updateSharedDataIncrement() {
        // std::lock(mutex1, mutex2); //
        std::try_lock(mutex1, mutex2); //
        // std::lock_guard<std::mutex> lock1(mutex1); // Захват мьютекса
        // std::lock_guard<std::mutex> lock2(mutex2); // Захват мьютекса

        std::cout << "MUTEX LOCKED with mutex1" << std::endl;
        sharedData++; // Обновление общих данных

        std::cout << "MUTEX LOCKED with mutex2" << std::endl;
        ++sharedData; // Обновление общих данных
}

void updateSharedDataDecrement() {
        std::try_lock(mutex1, mutex2); //
        // std::lock_guard<std::mutex> lock1(mutex1); // Захват мьютекса
        // std::lock_guard<std::mutex> lock2(mutex2); // Захват мьютекса
        std::cout << "MUTEX LOCKED with mutex2" << std::endl;
        --sharedData; // Обновление общих данных

        std::cout << "MUTEX LOCKED with mutex1" << std::endl;
        sharedData--; // Обновление общих данных
}

constexpr int countThreads = 100;

int main() {
    std::vector<std::thread> threads;
    for (size_t i = 0; i < countThreads; i++)
    {
        threads.push_back(std::thread(updateSharedDataIncrement));
        threads.push_back(std::thread(updateSharedDataDecrement));
    }

    for (auto& it : threads) {
        it.join();
    }
    

    std::cout << "Shared data: " << sharedData << std::endl;

    return 0;
}