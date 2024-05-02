#include <iostream>
#include <string>

template<typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;

    pair() : first(), second() {}
    pair(const T1& t1, const T2& t2) : first(t1), second(t2) {}

    // геттеры
    const T1& getFirst() const {
        return first;
    }
    const T2& getSecond() const {
        return second;
    }

    // сеттеры
    void setFirst(const T1& t1) {
        first = t1;
    }
    void setSecond(const T2& t2) {
        second = t2;
    }
};

// вывод в поток
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << ", " << p.second << \")\";\n    return os;
}

int main() {
    // тестирование на разных типах данных
    pair<int, int> int_pair(1, 2);
    std::cout << \"Int pair: " << int_pair << \"\\n";

    pair<std::string, double> str_dbl_pair("hello", 3.14159);
    std::cout << \"String-double pair: " << str_dbl_pair << \"\\n";

    pair<char, bool> char_bool_pair('A', true);
    std::cout << \"Char-bool pair: " << char_bool_pair << \"\\n";

    pair<float, int> float_int_pair(3.14, 42);
    std::cout << \"Float-int pair: " << float_int_pair << \"\\n";

    return 0;
}
