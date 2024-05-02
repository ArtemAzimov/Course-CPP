/*
3.  Реализация удаления элементов из контейнера с использованием итераторов. 
    Например, можно реализовать функцию, которая удалит все элементы из вектора, 
    удовлетворяющие определенному условию. 
    Это поможет показать, как можно использовать итераторы для модификации данных в контейнере.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

bool odd_func(int arg){
    return (arg % 2 != 0);
}

void filter(std::vector<int>& v) {
    auto it = std::remove_if(v.begin(), v.end(), odd_func);
    v.erase(it, v.end());
    std::cout << "---* FILTER USED" << std::endl;
}

int main(){
    std::vector<int> vec {1, 3, 5, 7, 10, 223, 333};
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << '\t';
        };
    std::cout << std::endl;

    filter(vec);

    for (it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << '\t';
    };
    std::cout << std::endl;

    // filter(vec);

    

    return 0;
}