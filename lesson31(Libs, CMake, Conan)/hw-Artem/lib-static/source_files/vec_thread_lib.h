#ifndef VEC_THREAD_LIB_H
#define VEC_THREAD_LIB_H

#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <mutex>

using uint = unsigned int;

//! Создает рандомный двумерный массив векторов
class Random_Vector_creator{
private:
    uint _vec_of_Vecs_size, _vec_of_Numbers_size;
public:
    //! Конструкторы
    Random_Vector_creator() : _vec_of_Vecs_size(10), _vec_of_Numbers_size(5){};
    Random_Vector_creator(uint argA, uint argB) : _vec_of_Vecs_size(argA), _vec_of_Numbers_size(argB){};
    
    //! Создает рандомный вектор
    std::vector<std::vector<double>> createRandomVector();

    //! Выводит вектор на экран
    void printVector(std::vector<std::vector<double>> const& vec_of_Vecs);
};


/**
 * @brief Чисто абстрактный класс
 * 
 */
class PredicateArithmetic_Base{
public:
    virtual void operation(std::vector<double>& _vec_of_Numbers) = 0;
};
class PredicateSquare : public PredicateArithmetic_Base{
public:
    //! Непосредственно вычисление квадрата. Захватывается тредом
    void operation(std::vector<double>& _vec_of_Numbers) override;
};
class PredicateIncrement : public PredicateArithmetic_Base{
public:
    void operation(std::vector<double>& _vec_of_Numbers) override;
};


class ThreadHandler{
    //! Мьютекс объявляется 1 раз при создании экземпляра ThreadHandler. Используется при вызове его функции
    mutable std::mutex mx;
public:
    //! Принимает указатель на базовый арифметик класс, полиморфизм
    void threadHandler(PredicateArithmetic_Base* predicate_func, std::vector<double>& vec_of_Numbers) const;
};

#endif // VEC_THREAD_LIB_H