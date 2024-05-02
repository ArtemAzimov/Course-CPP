#include <iostream>
#include <memory>

void foo(std::string *ptr) {
    std::cout << "foo " << *ptr  << std::endl;
}

int main(int, char**) {
    std::shared_ptr<std::string> pStr = std::make_shared<std::string>("Resources");    
    std::cout << "counters: " << pStr.use_count()<< std::endl;
    foo(pStr.get());
}
