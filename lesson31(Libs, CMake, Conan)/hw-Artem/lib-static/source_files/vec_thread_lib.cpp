#include "vec_thread_lib.h"

std::vector<std::vector<double>> Random_Vector_creator::createRandomVector(){
    std::vector<std::vector<double>> _vec_of_Vecs;
    for (size_t i = 0; i < _vec_of_Vecs_size; ++i){
        std::vector<double> numbersVector;
        for (int k = 0; k < _vec_of_Numbers_size; ++k){
            numbersVector.push_back(std::rand()%999 + 1);
        }
    _vec_of_Vecs.push_back(numbersVector);
    }
    return _vec_of_Vecs;
}
void Random_Vector_creator::printVector(std::vector<std::vector<double>> const& vec_of_Vecs){
    for (size_t i = 0; i < vec_of_Vecs.size(); ++i){
        std::cout << "Vector #" << i+1 << ": ";
        for (const auto& numbers: vec_of_Vecs[i]){
            std::cout << numbers << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void PredicateSquare::operation(std::vector<double>& _vec_of_Numbers){
    for (auto& value : _vec_of_Numbers){
        value = value*value;
    }
}
void PredicateIncrement::operation(std::vector<double>& _vec_of_Numbers){
    for (auto& value : _vec_of_Numbers){
        ++value;
    }
}


void ThreadHandler::threadHandler(PredicateArithmetic_Base* predicate_func, std::vector<double>& vec_of_Numbers) const {
    std::lock_guard<std::mutex> lock(mx);
    //! Указывает на виртуальную функцию, в зависимости от переданного объекта класса
    predicate_func->operation(vec_of_Numbers);   //!< КРИТИЧЕСКАЯ СЕКЦИЯ
}