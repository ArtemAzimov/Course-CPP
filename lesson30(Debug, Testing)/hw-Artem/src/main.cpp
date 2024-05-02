#include "threadmaster.hpp"
// #include <gtest/gtest.h>
#include <vector>

// void Class_instance(int(int*lambda), int coun){
//     FuturesPool<int(int), int> myPool;

//     std::vector<std::function<int(int)>> tasks;
//     for (int i = 0; i < count; ++i)
//     {
//         tasks.push_back(lambda);
//     }
//     myPool.start_threads(tasks);
// }

// TEST(Class_instance, PositiveNumbers) {
//     auto lambda = [=](int i){
//         return i;
//     };
//     std::vector<int> result = Class_instance(lambda, 2);
//     EXPECT_EQ(result, {1, 2});
// }

// int main(int argc, char** argv) {
//     ::testing::InitGoogleTest(&argc, argv);
    
//     return RUN_ALL_TESTS();
// }

int main(){
    FuturesPool<int(int), int> myPool;

    auto lambda = [=](int i){
        return i;
    };

    std::vector<std::function<int(int)>> tasks;
    for (int i = 0; i < 5; ++i)
    {
        tasks.push_back(lambda);
    }
    myPool.start_threads(tasks);
    std::vector<int> result = myPool.getResult();
    for (auto& s : result){
        std::cout << s << ", ";
    }
}
