/**
 * @file future_vec_queue.cpp
 * @brief Домашнее задание по теме "Многопоточность". Сколько на машине потоков? Максимально использовать железо с помощью future.
 * Сравнить время, сделать тесты с одним и несколькими потоками.
 * @date 2023-06-08
 * 
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>
#include <chrono>

/**
 * @brief Класс выделяет указанное число потоков (по умолчанию - все доступные) для выполнения переданных классу функций.
 * Можно указать размер очереди функций (по умолчанию 4) - программа будет ожидать заполнения очереди до указанного размера.
 * Затем она передаст пакет функций заданного размера, пакет будет разбит на число потоков, потоки будут запущены асинхронно.
 * ПРИМЕР: Число потоков 2, размер пакета 10, переданы 20 функций.
 * Программа будет выполнена в 2 итерации - в каждой будут запущены асинхронно 2 потока по 5 функций в каждом.
 * 
 */
class Futures_Vector{
private:
    unsigned int _num_of_threads;
    unsigned int _task_pack_capacity;
    std::queue<std::function<void(int)>> _task_queue;
    std::condition_variable _cv;
    std::mutex _mx;
    int _task_index = 0;
public:
    /**
     * @brief Конструктор по умолчанию. По умолчанию использовать все доступные потоки, вместимость очереди задач 4.
     * 
     */
    Futures_Vector() : _num_of_threads(std::thread::hardware_concurrency()), _task_pack_capacity(4){
        std::cout << "*** Number of concurrent threads on this machine: " << _num_of_threads << std::endl;
    }

    void set_num_of_threads(unsigned int const user_num_of_threads){
        if (user_num_of_threads > _num_of_threads){
            throw std::runtime_error("Can't use more threads than machine has");
        }
        else{
            _num_of_threads = user_num_of_threads;
            std::cout << "*** Using " << _num_of_threads << " thread(-s)" << std::endl;
        }
    }

    void set_task_capacity(unsigned int const user_task_pack_capacity){
        if (user_task_pack_capacity < 1){
            throw std::runtime_error("Only natural numbers allowed");
        }
        else{
            _task_pack_capacity = user_task_pack_capacity;
            std::cout << "*** Task capacity is " << _task_pack_capacity << std::endl;
        }
    }

    void producer(std::function<void(int)> task){
        {
            std::unique_lock<std::mutex> lock(_mx);
            _task_queue.push(task);
        }
        //! Уведомить Консумера при поступлении таски в очередь
        _cv.notify_one();
    }

    void consumer(){
        while (true){
            std::vector<std::function<void(int)>> tasks_vector;
            { // SCOPE OF MUTEX
                std::unique_lock<std::mutex> lock(_mx);
                //! Консумер ждет пока кол-во тасок в очереди будет равно _task_pack_capacity
                _cv.wait(lock, [this]() {return _task_queue.size() >= _task_pack_capacity;});
                std::cout << "--Task queue is full. Consumer notified" << std::endl;

                //! Переместить таски из очереди в вектор размером равным пакету тасок
                for (int i = 0; i < _task_pack_capacity; ++i) {
                    tasks_vector.push_back(_task_queue.front());
                    _task_queue.pop();
                    // std::cout << "--Task queue size: " << _task_queue.size() << std::endl;
                }

                //! Установить диапазон (кол-во тасок в 1 треде) по формуле: кол-во тасок в пакете/кол-во потоков
                int diap = _task_pack_capacity / _num_of_threads;
                std::cout << "--There will be " << diap << " task(-s) running in each thread" << std::endl;
                
                std::vector<std::future<void>> futures;
                //! Для каждого пакета тасок создать фьючер, в котором будут выполняться таски из этого пакета
                for (int package_number = 0; package_number < _task_pack_capacity / diap; ++package_number){
                    futures.push_back(std::async(std::launch::async, [&](){
                        for (int i = 0; i < diap; ++i){
                            tasks_vector[i](_task_index);
                            ++_task_index;
                        }
                    }));
                }
                //! Получить результат фьючеров
                for (auto& tasks : futures){
                    tasks.get();
                }
                std::cout << "*** ITERATION COMPLETED SUCCESFULLY" << std::endl;
            } // END SCOPE OF MUTEX
            //! Консумер ждет 0,5 сек и если очередь пуста - выходит из цикла, программа завершается
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            if(_task_queue.empty()){
                break;
            }
        }
    }
};

int main(){
    try
    {
        //! Создать объект, задать кол-во тредов и размер очереди тасок
        Futures_Vector myVec;
        myVec.set_num_of_threads(2);
        myVec.set_task_capacity(10);

        //! Создать отдельный тред с Консумером
        std::thread thread(&Futures_Vector::consumer, &myVec);

        //! Передать в Продюсер n кол-во тасок
        for (size_t i = 0; i < 20; i++){
            myVec.producer([=](int value){
                std::cout << "Task result: " << value+100 << std::endl;
            });
        }

        //! Заджоинить тред с Консумером
        thread.join();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return  EXIT_SUCCESS;
}