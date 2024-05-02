#include <iostream>
#include <memory>

class Person
{
public:
    std::string name;
    Person(std::string name) : name(name)
    {
        std::cout << name << " created." << std::endl;
    }
    ~Person()
    {
        std::cout << name << " destroyed." << std::endl;
    }
};

int main()
{
    {
        std::shared_ptr<Person> personPtr(new Person("Alice"), [](Person *person)
                                          { delete person; });
        std::cout << "Counter " << personPtr.use_count() << std::endl;
        std::weak_ptr<Person> weakPtr = personPtr;
        std::cout << "Counter " << personPtr.use_count() << std::endl;

        std::cout << "Before deleting personPtr...\n";
        if (auto sharedPtr = weakPtr.lock())
        {
            std::cout << "Accessing " << sharedPtr->name << " through weak pointer.\n";
            std::cout << "Counter " << personPtr.use_count() << std::endl;
        }
        else
        {
            std::cout << "Object already deleted.\n";
        }

        // personPtr.reset(); // deleting the shared_ptr
        std::cout << "Counter " << personPtr.use_count() << std::endl;
    }
    // 1000 linese of code

    std::cout << "After deleting personPtr...\n";
    if (auto sharedPtr = weakPtr.lock())
    {
        std::cout << "Accessing " << sharedPtr->name << " through weak pointer.\n";
    }
    else
    {
        std::cout << "Object already deleted.\n";
    }

    return 0;
}
