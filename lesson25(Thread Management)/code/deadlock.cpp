#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1;
std::mutex mutex2;

void ThreadA()
{
    std::cout << "Thread A started" << std::endl;
    
    // Lock mutex1
    mutex1.lock();
    std::cout << "Thread A acquired mutex1" << std::endl;
    
    // Sleep for a while to simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    // Attempt to lock mutex2
    mutex2.lock();
    std::cout << "Thread A acquired mutex2" << std::endl;
    
    // Critical section
    std::cout << "Thread A is inside the critical section" << std::endl;
    
    // Unlock mutex2
    mutex2.unlock();
    std::cout << "Thread A released mutex2" << std::endl;
    
    // Unlock mutex1
    mutex1.unlock();
    std::cout << "Thread A released mutex1" << std::endl;
}

void ThreadB()
{
    std::cout << "Thread B started" << std::endl;
    
    // Lock mutex2
    mutex2.lock();
    std::cout << "Thread B acquired mutex2" << std::endl;
    
    // Sleep for a while to simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    // Attempt to lock mutex1
    mutex1.lock();
    std::cout << "Thread B acquired mutex1" << std::endl;
    
    // Critical section
    std::cout << "Thread B is inside the critical section" << std::endl;
    
    // Unlock mutex1
    mutex1.unlock();
    std::cout << "Thread B released mutex1" << std::endl;
    
    // Unlock mutex2
    mutex2.unlock();
    std::cout << "Thread B released mutex2" << std::endl;
}

int main()
{
    std::thread t1(ThreadA);
    std::thread t2(ThreadB);
    
    t1.join();
    t2.join();
    
    return 0;
}
