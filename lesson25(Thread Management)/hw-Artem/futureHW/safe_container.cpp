/**
 * @file safe_container.cpp
 * @brief Потокобезопасный контейнер — контейнер, который исключает состояние гонки данных при обращении к его данным.
 * @date 2023-06-09
 * 
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <mutex>
#include <thread>
#include <chrono>
#include <initializer_list>
#include <atomic>

/**
 * @brief Класс-шаблон потокобезопасного вектора
 * 
 * @tparam T 
 */
template <typename T>
class Safe_Vector{
private:
    std::vector<T> _vec;
    std::mutex _mtx;
public:
    Safe_Vector(){};
    Safe_Vector(std::initializer_list<T> list){
        _vec = {list};
    };

    void print(){
        for (const auto& elem : _vec){
            std::cout << elem << '\t';
        }
        std::cout << std::endl;
    }

    /**
     * @brief Устранение проблемы условной гонки
     * 
     * @param value 
     */
    void safe_push_back(T value){
        std::lock_guard<std::mutex> lock(_mtx);
        _vec.push_back(value);
        // while (true){
        //     if (_mtx.try_lock()){
        //         _vec.push_back(value);
        //         _mtx.unlock();
        //         break;
        //     }
        //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // }
    }

    void unsafe_push_back(T value){
        _vec.push_back(value);
    }
};

void TEST_UNSAFE_VECTOR(const int& num_of_threads){
    Safe_Vector<int> myUnsafeVec;
    std::vector<std::thread> threads;

    for (int i = 1; i <= num_of_threads; i++){
        threads.push_back(std::thread(&Safe_Vector<int>::unsafe_push_back, &myUnsafeVec, i));
    }

    for (auto& thread : threads){
        thread.join();
    }

    std::cout << "*** Unsafe vector:" << std::endl;
    myUnsafeVec.print();
}

void TEST_SAFE_VECTOR(const int& num_of_threads){
    Safe_Vector<int> mySafeVec;
    std::vector<std::thread> threads;
    
    for (int i = 1; i <= num_of_threads; i++){
        threads.push_back(std::thread(&Safe_Vector<int>::safe_push_back, &mySafeVec, i));
    }

    for (auto& thread : threads){
        thread.join();
    }

    std::cout << "*** Safe vector:" << std::endl;
    mySafeVec.print();
}

int main(){
    try
    {
        int num_of_threads = 1000;
        TEST_UNSAFE_VECTOR(num_of_threads);
        TEST_SAFE_VECTOR(num_of_threads);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return EXIT_SUCCESS;
}