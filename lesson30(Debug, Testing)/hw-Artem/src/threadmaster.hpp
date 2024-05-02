#ifndef THREADMASTER_HPP
#define THREADMASTER_HPP

#include <iostream>
#include <vector>
#include <future>
#include <functional>
#include <mutex>
#include <thread>

using uint = unsigned int;

template <typename SignatureType, typename ReturnType>
class ThreadMaster{
protected:
    uint _num_of_threads;
    std::vector<ReturnType> res;
public:
    ThreadMaster() : _num_of_threads(std::thread::hardware_concurrency()){

    };
    virtual void start_threads(std::vector<std::function<SignatureType>>& taskVec) = 0;
};

template <typename SignatureType, typename ReturnType>
class FuturesPool : public ThreadMaster<SignatureType, ReturnType>{
public:
    using ThreadMaster<SignatureType, ReturnType>::ThreadMaster;

    void start_threads(std::vector<std::function<SignatureType>>& taskVec){
        std::cout << "*** Using " << this->_num_of_threads << " thread(-s)" << std::endl;

        std::vector<std::future<ReturnType>> futures;
        bool isEven = (taskVec.size() % 2 == 0);
        isEven ? std::cout << "isEven\n" : std::cout << "isOdd\n";

        int size = taskVec.size();
        int j = 0;
        if(!isEven){
            std::cout << "* New future thread started" << std::endl;
            futures.push_back(std::async(std::launch::async, taskVec[0], j));
            std::cout << "* Odd Task #" << j << " started" << std::endl;
            ++j;
        }

        for (int i = 0; i < this->_num_of_threads; ++i){
            std::cout << "* New future thread started" << std::endl;
            for (j; j < taskVec.size() / this->_num_of_threads; ++j){
                futures.push_back(std::async(std::launch::async, taskVec[j], j));
                std::cout << "* Task #" << j << " started" << std::endl; 
            }
        }

        for (auto& task : futures){
            this->res.push_back(task.get());
        }
        for (auto& s : this->res){
            std::cout << s << ", ";
        }
        std::cout << std::endl;
    }

    std::vector<ReturnType> getResult(){
        return this->res;
    }
};

#endif // THREADMASTER_HPP