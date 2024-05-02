#include <iostream>
#include <vector>

// не работал с вектором

template<typename T>
std::vector<T> Filter(const T& container, void* func)
{
    std::vector<T> res;
    for (const T& i : container)
    {
        if (func == true)
        {
            res.push_back(i);
        }
    }
    return res;
}


int main()
{
    return 0;
}


/*  ChatGPT solution

template <typename T>
std::vector<T> filter(std::vector<T> const& vec, std::function<bool(T)> predicate)
{
    std::vector<T> result;
    for (auto const& item : vec)
    {
        if (predicate(item))
        {
            result.push_back(item);
        }
    }
    return result;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto even = [](int x) { return x % 2 == 0; };
    auto result = filter(vec, even);
}

*/