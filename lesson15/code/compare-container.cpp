#include <iostream>
#include <chrono>
#include <vector>
#include <array>
#include <unordered_map>

const int ELEMENTS = 1000000;

int main() {
    // Array
    std::array<int, ELEMENTS> arr;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ELEMENTS; i++) {
        arr[i] = i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> arrAddTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ELEMENTS; i++) {
        int val = arr[i];
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> arrGetTime = end - start;

    std::cout << "Array Time to add: " << arrAddTime.count() << "\n";
    std::cout << "Array Time to get: " << arrGetTime.count() << "\n";
    std::cout << "Array Size: " << sizeof(arr) << " bytes\n";

    // Vector
    std::vector<int> vec;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ELEMENTS; i++) {
        vec.push_back(i);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> vecAddTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ELEMENTS; i++) {
        int val = vec[i];
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> vecGetTime = end - start;

    std::cout << "Vector Time to add: " << vecAddTime.count() << "\n";
    std::cout << "Vector Time to get: " << vecGetTime.count() << "\n";
    std::cout << "Vector Size: " << sizeof(vec) << " bytes\n";

    // Unordered Map
    std::unordered_map<int, int> mp;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ELEMENTS; i++) {
        mp[i] = i;
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mpAddTime = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ELEMENTS; i++) {
        int val = mp[i];
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mpGetTime = end - start;

    std::cout << "Unordered Map Time to add: " << mpAddTime.count() << "\n";
    std::cout << "Unordered Map Time to get: " << mpGetTime.count() << "\n";
    std::cout << "Unordered Map Size: " << sizeof(mp) << " bytes\n";

    return 0;
}
