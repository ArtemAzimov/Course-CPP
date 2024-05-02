#include <iostream>
#include <vector>
#include <algorithm>

void filter(std::vector<int>& v) {
    auto it = std::remove_if(v.begin(), v.end(), even_func);
    v.erase(it, v.end());
}

bool even_func(int arg){
    return (arg % 2 != 0);
}

int main(){
    std::vector<int> vec {1, 3, 5, 7, 10, 223, 333};
    

    return 0;
}