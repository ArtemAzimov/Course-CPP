#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int threadCount = 0;

void WorkerThread()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::unique_lock<std::mutex> lock(mtx);
    ++threadCount;
    auto t = threadCount;
    std::cout << "Thread Count: " << t << std::endl;

    if (threadCount < 7) {
        cv.wait(lock);
    } else {
        cv.notify_all();
    }

    std::cout << "Thread " << t << " " << std::this_thread::get_id() << " started" << std::endl;
}

int main()
{
    std::thread thread1(WorkerThread);
    std::thread thread2(WorkerThread);
    std::thread thread3(WorkerThread);
    std::thread thread4(WorkerThread);
    std::thread thread5(WorkerThread);
    std::thread thread6(WorkerThread);
    std::thread thread7(WorkerThread);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();

    std::cout << "All threads started" << std::endl;

    return 0;
}