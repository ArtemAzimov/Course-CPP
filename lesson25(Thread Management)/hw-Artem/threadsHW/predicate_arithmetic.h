#ifndef PREDICATE_ARITHMETIC_H
#define PREDICATE_ARITHMETIC_H

#include <vector>

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
    void operation(std::vector<double>& _vec_of_Numbers) override{
        for (auto& value : _vec_of_Numbers){
            value = value*value;
        }
    }
};
class PredicateIncrement : public PredicateArithmetic_Base{
public:
    void operation(std::vector<double>& _vec_of_Numbers) override{
        for (auto& value : _vec_of_Numbers){
            ++value;
        }
    }
};

#endif // PREDICATE_ARITHMETIC_H
