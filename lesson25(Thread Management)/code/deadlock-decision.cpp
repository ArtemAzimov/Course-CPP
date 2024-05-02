#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1;
std::mutex mutex2;

void deadlockAvoidanceThread()
{
    // Acquiring locks using std::lock to avoid deadlocks
    std::lock(mutex1, mutex2);

    // Critical section protected by mutex1 and mutex2
    std::cout << "Executing deadlockAvoidanceThread's critical section." << std::endl;

    mutex1.unlock();
    mutex2.unlock();
}

void potentialDeadlockThread()
{
    // Potential deadlock scenario without using std::lock
    mutex2.lock();
    mutex1.lock(); // Locks acquired in reverse order compared to deadlockAvoidanceThread

    // Critical section protected by mutex1 and mutex2
    std::cout << "Executing potentialDeadlockThread's critical section." << std::endl;

    mutex1.unlock();
    mutex2.unlock();
}

int main()
{
    std::thread t1(deadlockAvoidanceThread);
    std::thread t2(potentialDeadlockThread);

    t1.join();
    t2.join();

    return 0;
}
