#include <iostream>
#include <vector>
#include <list>
#include <set>

int main()
{
    {
        std::vector<int> vec{1, 2, 3, 4, 5};

        // Вывод элементов контейнера с помощью итератора
        std::cout << "Elements of vector:";
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << " " << *it;
        }
        std::cout << std::endl;

        // Удаление элементов из контейнера с помощью итератора
        auto it = vec.begin();
        while (it != vec.end())
        {
            if (*it % 2 == 0)
            {
                it = vec.erase(it);
            }
            else
            {
                ++it;
            }
        }

        // Вывод измененного контейнера с помощью итератора
        std::cout << "Elements of vector after removing even numbers:";
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
    {
        std::list<int> lst{1, 2, 3, 4, 5};

        // Вывод элементов контейнера с помощью итератора
        std::cout << "Elements of list:";
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            std::cout << " " << *it;
        }
        std::cout << std::endl;

        // Удаление элементов из контейнера с помощью итератора
        auto it = lst.begin();
        while (it != lst.end())
        {
            if (*it % 2 == 0)
            {
                it = lst.erase(it);
            }
            else
            {
                ++it;
            }
        }

        // Вывод измененного контейнера с помощью итератора
        std::cout << "Elements of list after removing even numbers:";
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }

    {
        std::set<int> st{1, 2, 3, 4, 5};

        // Вывод элементов контейнера с помощью итератора
        std::cout << "Elements of set:";
        for (auto it = st.begin(); it != st.end(); ++it)
        {
            std::cout << " " << *it;
        }
        std::cout << std::endl;

        // Удаление элементов из контейнера с помощью итератора
        auto it = st.begin();
        while (it != st.end())
        {
            if (*it % 2 == 0)
            {
                it = st.erase(it);
            }
            else
            {
                ++it;
            }
        }

        // Вывод измененного контейнера с помощью итератора
        std::cout << "Elements of list after removing even numbers:";
        for (auto it = st.begin(); it != st.end(); ++it)
        {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }

    return 0;
}