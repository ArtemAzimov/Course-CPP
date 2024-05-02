// Code example for introduction to SOLID principles in C++

#include <iostream>
#include <string>

// Single Responsibility Principle (SRP)
class User {
private:
    std::string name;
public:
    void setName(std::string userName) {
        name = userName;
    }
    std::string getName() {
        return name;
    }
};

// Open/Closed Principle (OCP)
class Shape {
public:
    virtual float area() = 0;
};

class Rectangle : public Shape {
private:
    float length;
    float width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float area() override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}
    float area() override {
        return 3.14 * radius * radius;
    }
};

// Liskov Substitution Principle (LSP)
class Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public Bird {
public:
    void fly() override {
        std::cout << "Sparrow can fly
";
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        throw(std::string("Ostrich can't fly"));
    }
};

// Interface Segregation Principle (ISP)
class Document {};

class IPrinter {
public:
    virtual void print(Document& d) = 0;
};

class Printer : public IPrinter {
public:
    void print(Document& d) override {
        std::cout << "Printing document...\n";
    }
};

class IFax {
public:
    virtual void fax(Document& d) = 0;
};

class Fax : public IFax {
public:
    void fax(Document& d) override {
        std::cout << "Faxing document...\n";
    }
};

class IMachine : public IPrinter, public IFax {};

// Dependency Inversion Principle (DIP)
class Database {
public:
    virtual void getData() = 0;
};

class MySql : public Database {
public:
    void getData() override {
        std::cout << "Getting data from MySQL database...\n";
    }
};

class Oracle : public Database {
public:
    void getData() override {
        std::cout << "Getting data from Oracle database...\n";
    }
};

int main() {
    // Single Responsibility Principle (SRP)
    User user;
    user.setName("John");
    std::cout << "User name is: " << user.getName() << std::endl;
    
    // Open/Closed Principle (OCP)
    Shape* shape = new Rectangle(4, 5);
    std::cout << "Rectangle area is: " << shape->area() << std::endl;
    delete shape;
    
    shape = new Circle(1);
    std::cout << "Circle area is: " << shape->area() << std::endl;
    delete shape;
    
    // Liskov Substitution Principle (LSP)
    Bird* bird = new Sparrow();
    bird->fly();
    delete bird;
    
    bird = new Ostrich();
    try {
        bird->fly();
    } catch (const std::string& err) {
        std::cout << err << std::endl;
    }
    delete bird;
    
    // Interface Segregation Principle (ISP)
    Document document;
    Printer printer;
    Fax fax;
    
    printer.print(document);
    fax.fax(document);
    
    // Dependency Inversion Principle (DIP)
    Oracle oracle;
    MySql mySql;
    
    IMachine machine(&oracle);
    machine.print(document);
    machine.fax(document);
    
    Database* database = &mySql;
    database->getData();
    database = &oracle;
    database->getData();
    
    return 0;
}
