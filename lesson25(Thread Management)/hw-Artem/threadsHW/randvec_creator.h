/**
    [-] комменты в хедере, doxygen
    [+] predicate VectorArithmetic
    [+] пересмотреть mainVector выдача объекта класса
    [-] сделать одну имплементацию threadHandler
    [-] sharedLock для чтения
    [-] дубликаты - readbuffer
    [-] shared lock
*/

#ifndef RANDVEC_CREATOR_H
#define RANDVEC_CREATOR_H

#include <vector>
#include <random>
#include <iostream>

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
    std::vector<std::vector<double>> createRandomVector(){
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

    //! Выводит вектор на экран
    void printVector(std::vector<std::vector<double>> const& vec_of_Vecs){
        for (size_t i = 0; i < vec_of_Vecs.size(); ++i){
            std::cout << "Vector #" << i+1 << ": ";
            for (const auto& numbers: vec_of_Vecs[i]){
                std::cout << numbers << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // RANDVEC_CREATOR_H
