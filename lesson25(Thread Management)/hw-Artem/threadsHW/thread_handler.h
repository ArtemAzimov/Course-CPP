#ifndef THREAD_HANDLER_H
#define  THREAD_HANDLER_H

#include "predicate_arithmetic.h"
#include "randvec_creator.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

namespace thread_handler{

class ThreadHandler{
    //! Мьютекс объявляется 1 раз при создании экземпляра ThreadHandler. Используется при вызове его функции
    mutable std::mutex mx;
public:
    //! Принимает указатель на базовый арифметик класс, полиморфизм
    void threadHandler(PredicateArithmetic_Base* predicate_func, std::vector<double>& vec_of_Numbers) const;
};

void ThreadHandler::threadHandler(PredicateArithmetic_Base* predicate_func, std::vector<double>& vec_of_Numbers) const {
    std::lock_guard<std::mutex> lock(mx);
    // int _vecCount = 1;
    //! Указывает на виртуальную функцию, в зависимости от переданного объекта класса
    predicate_func->operation(vec_of_Numbers);   //!< КРИТИЧЕСКАЯ СЕКЦИЯ
}
} // end of namespace thread_handler

#endif // THREAD_HANDLER_H
