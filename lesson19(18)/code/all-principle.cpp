#include <iostream>
#include <string>

// Single Responsibility Principle (SRP)
class FileHandler {
public:
    void readFromFile(const std::string& fileName) {
        std::cout << "Reading data from file: " << fileName << std::endl;
        // Read data from the file
    }

    void writeToFile(const std::string& fileName, const std::string& data) {
        std::cout << "Writing data to file: " << fileName << std::endl;
        // Write data to the file
    }
};

// Open-Closed Principle (OCP)
class Shape {
public:
    virtual double calculateArea() const = 0;
};

// // Liskov Substitution Principle (LSP)
void printShapeArea(const Shape& shape) {
    double area = shape.calculateArea();
    std::cout << "Area: " << area << std::endl;
}

// Interface Segregation Principle (ISP)
class Drawable {
public:
    virtual void draw() const = 0;
};

class Resizable {
public:
    virtual void resize(double factor) = 0;
};

class Circle : public Shape, public Drawable {
public:
    double calculateArea() const override {
        // Calculate and return the area of a circle
        return 3.14159 * radius_ * radius_;
    }

    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
        // Draw a circle
    }

    void setRadius(double radius){
        radius_ = radius;
    }

private:
    double radius_;
};

class Rectangle : public Shape, public Drawable, public Resizable {
public:
    double calculateArea() const override {
        // Calculate and return the area of a rectangle
        return width_ * height_;
    }

    void draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;
        // Draw a rectangle
    }

    void resize(double factor) override {
        std::cout << "Resizing a rectangle by factor: " << factor << std::endl;
        width_ = width_ * factor;
        height_ = height_ * factor;
        // Resize the rectangle by a given factor
    }

    void setHeight(double height) {
        height_ = height;
    }

    void setWidth(double width){
        width_ = width;
    }

private:
    double width_;
    double height_;
};

int main() {
    FileHandler fileHandler;
    fileHandler.readFromFile("data.txt");
    fileHandler.writeToFile("output.txt", "Hello, SOLID!");

    Circle circle;
    circle.setRadius(10);
    Rectangle rectangle;
    rectangle.setHeight(10);
    rectangle.setWidth(5);

    printShapeArea(circle);
    printShapeArea(rectangle);

    circle.draw();
    rectangle.draw();

    rectangle.resize(1.5);
    printShapeArea(rectangle);

    return 0;
}
