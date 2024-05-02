#include "vec_thread_lib.h"
#include <chrono>

void TEST_WITH_THREADS(PredicateArithmetic_Base* ptr_predicate_obj, std::vector<std::vector<double>>& vector_of_vectors){
    std::vector<std::thread> threadVec;
    //! Инициализация мьютекса
    const ThreadHandler th;

    //! Возвести в квадрат все элементы вектора (или инкрементировать)
    for (auto& itVec : vector_of_vectors){
        /** 
            Передать ссылку на функцию threadHandler, ссылку на вызывающий экземпляр ThreadHandler, 
            вектор по ссылке& и экземпляр класса VectorArithmetic по ссылке& в обертке std::ref. 
            Без std::ref — ошибка "static assertion", т.к. мы изменяем вектор по ссылке и
            указатель на ресурс должен ссылаться на один и тот же адрес в памяти (физически),
            см. "std::thread const rvalue" (thread неявно копирует const reference для безопасности треда)
        */
        threadVec.push_back(std::thread(&ThreadHandler::threadHandler, &th, std::ref(ptr_predicate_obj), std::ref(itVec)));
    }
    for (auto& thread : threadVec){
        thread.join();
    }
}

void TEST_NO_THREADS(std::vector<std::vector<double>>& vector_of_vectors){
    for (auto& itVec : vector_of_vectors){
        for (auto& value : itVec){
            value = value*value;
        }
    }
}

int main(){    
    try
    {
        //! Инициализировать объект класса рандомный вектор
        Random_Vector_creator myRandomVector(3, 3);
        auto myVec = myRandomVector.createRandomVector();
        std::cout << "*** Vectors before changes\n";
        myRandomVector.printVector(myVec);

        auto start = std::chrono::system_clock::now();
        
        //! Инициализировать объект дочерних классов арифметики вектора
        PredicateIncrement do_increment;
        TEST_WITH_THREADS(&do_increment, myVec);
        std::cout << "*** Vectors after incrementing" << std::endl;
        myRandomVector.printVector(myVec);

        PredicateSquare do_square;
        TEST_WITH_THREADS(&do_square, myVec);
        std::cout << "*** Vectors after squaring" << std::endl;
        myRandomVector.printVector(myVec);
        
        // TEST_NO_THREADS(myVec);

        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "*** Number of concurrent threads on this machine: " << std::thread::hardware_concurrency() << std::endl;
        std::cout << "*** Computations completed in: " << elapsed.count() << " milliseconds\n" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}