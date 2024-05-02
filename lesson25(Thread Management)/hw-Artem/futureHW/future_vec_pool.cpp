/**
 * @file future_vec_pool.cpp
 * @brief Домашнее задание по теме "Многопоточность". Сколько на машине потоков? Максимально использовать железо с помощью future.
 * Сравнить время, сделать тесты с одним и несколькими потоками.
 * @date 2023-06-07
 * 
 */
#include <iostream>
#include <vector>
#include <future>
#include <stdexcept>

/**
 * @brief Класс выделяет указанное число потоков для выполнения переданных функции.
 * 
 */
class Futures_Vector{
private:
    unsigned int _num_of_threads;
public:
    /** По умолчанию использовать все доступные потоки */
    Futures_Vector() : _num_of_threads(std::thread::hardware_concurrency()){
        std::cout << "*** Number of concurrent threads on this machine: " << _num_of_threads << std::endl;
    }

    /**
     * @brief Set the num of threads object
     * 
     * @param user_num_of_threads 
     */
    void set_num_of_threads(unsigned int const user_num_of_threads){
        if (user_num_of_threads > _num_of_threads){
            throw std::runtime_error("Can't use more threads than machine has");
        }
        else{
            _num_of_threads = user_num_of_threads;
        }
    }

    void start_futures(std::vector<std::function<void(int)>>& taskVec){
        std::cout << "*** Using " << _num_of_threads << " thread(-s)" << std::endl;

        std::vector<std::future<void>> futures;
        int diap = taskVec.size() / _num_of_threads;
        std::cout << "diap: " << diap << std::endl;

        int j = 0;
        for(auto i = 0; i < _num_of_threads; ++i){
            std::cout << "*** New thread #" << i << " started" << std::endl;
            futures.push_back(std::async(std::launch::async, [&diap, &i, &j, &taskVec](){
                for (j; j < diap*i; ++j){
                    std::cout << "* Task #" << j << " started" << std::endl;
                    taskVec[j](j);
                }
            }));
        }
        for (auto& tasks : futures){
            tasks.get();
        }
    }
};

int main(){
    try
    {
        Futures_Vector myVec;
        // myVec.set_num_of_threads(1);

        auto default_task = [=](int i){
            std::cout << "Task result: " << i+100 << std::endl;
        };

        std::vector<std::function<void(int)>> tasks;
        for (size_t i = 0; i < 4; i++)
        {
            tasks.push_back(default_task);
        }
        myVec.start_futures(tasks);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return  EXIT_SUCCESS;
}