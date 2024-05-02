#include <vector>
#include <iostream>
#include <algorithm>

class GreaterThan {
    private:
        int m_threshold;
    public:
        GreaterThan(int threshold) : m_threshold(threshold) {}
        bool operator() (int value) const {
            return value > m_threshold;
        }
};

bool greaterThan(int value){
    return value > 3;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    // vec.erase(std::remove_if(vec.begin(), vec.end(), GreaterThan(3)), vec.end());
    // int threshold = 3;
    // auto lamda = [threshold](int v){return v > threshold;};
    // vec.erase(std::remove_if(vec.begin(), vec.end(), lamda), vec.end());
    vec.erase(std::remove_if(vec.begin(), vec.end(), greaterThan), vec.end());
    for (int i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}