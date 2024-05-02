#include <iostream>

class Shape {
public:
    virtual double getArea() const = 0;
};

class Rectangle : public Shape {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }
};

class Square : public Shape {
protected:
    double side;

public:
    Square(double s) : side(s) {}

    double getArea() const override {
        return side * side;
    }

    void setSide(double s) {
        side = s;
    }
};

void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.getArea() << std::endl;
}

int main() {
    Rectangle rectangle(3.0, 4.0);
    Square square(5.0);

    printArea(rectangle);  // Выводит "Area: 12"
    printArea(square);    // Выводит "Area: 25"

    // Принцип подстановки Барбары Лисков:
    Shape& shapeRef = square;
    shapeRef = rectangle;  // Присваиваем объекту square объект rectangle
    printArea(shapeRef);   // Выводит "Area: 12"

    return 0;
}
