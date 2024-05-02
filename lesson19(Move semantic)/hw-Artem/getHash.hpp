#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/*
Алгоритм хэширования djb2.

Для каждого символа строки вычисляется хэш-код, который добавляется к общему значению хэша. 
Затем общее значение умножается на 33 и добавляется код следующего символа.
*/
class Hash {
private:
    unsigned int hash;
public:
    Hash() : hash(322) {}

    void add(const std::string& str) {
        for (char c : str)
            hash = ((hash << 5) + hash) + c;
    }

    unsigned int get() const {
        return hash;
    }
};

unsigned int getHash(const std::filesystem::path& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    Hash hash;
    hash.add(buffer.str());

    return hash.get();
}
