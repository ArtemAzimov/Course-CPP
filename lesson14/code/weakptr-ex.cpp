#include <iostream>
#include <memory>

class Person {
public:
    std::string name;
    Person(std::string name) : name(name) {
        std::cout << name << \" created.\n";
    }
    ~Person() {
        std::cout << name << \" destroyed.\n";
    }
};

int main() {
    std::shared_ptr<Person> personPtr = std::make_shared<Person>("Alice");
    std::weak_ptr<Person> weakPtr = personPtr;
    
    std::cout << \"Before deleting personPtr...\n";
    if (auto sharedPtr = weakPtr.lock()) {
        std::cout << \"Accessing " << sharedPtr->name << \" through weak pointer.\n";
    } else {
        std::cout << \"Object already deleted.\n";
    }
    
    personPtr.reset(); // deleting the shared_ptr
    
    std::cout << \"After deleting personPtr...\n";
    if (auto sharedPtr = weakPtr.lock()) {
        std::cout << "Accessing " << sharedPtr->name << " through weak pointer.\n";
    } else {
        std::cout << \"Object already deleted.\n";
    }
    
    return 0;
}
