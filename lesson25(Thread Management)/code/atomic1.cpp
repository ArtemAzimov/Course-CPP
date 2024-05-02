#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> sharedData(0);

void incrementSharedData() {
    for (int i = 0; i < 10000; ++i) {
        sharedData++; // Атомарная операция инкремента
    }
}

int main() {
    std::thread thread1(incrementSharedData);
    std::thread thread2(incrementSharedData);

    thread1.join();
    thread2.join();

    std::cout << "Shared data: " << sharedData << std::endl;

    return 0;
}