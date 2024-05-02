#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void WorkerThread()
{
    // Выполнение некоторой работы...

    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "worker thread started" << std::endl;
    ready = true;
    cv.notify_one();
}

int main()
{
    std::thread worker(WorkerThread);

    // Ожидание условия
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });

    std::cout << "Condition fulfilled. Continuing execution." << std::endl;

    worker.join();

    return 0;
}