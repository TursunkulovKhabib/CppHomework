#include <vector>
#include <numbers>
#include <cmath>
#include <iostream>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
};

class Triangle final : public Shape {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double perimeter() const override final {
        return side1 + side2 + side3;
    }

    double area() const override final {
        double p = perimeter() / 2;
        return std::sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
};

class Square final : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double perimeter() const override {
        return 4 * side;
    }

    double area() const override {
        return side * side;
    }
};

class Circle final : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double perimeter() const override {
        return 2 * std::numbers::pi * radius;
    }

    double area() const override {
        return std::numbers::pi * radius * radius;
    }
};

int main() {
    std::vector<Shape*> shapes;
    
    shapes.push_back(new Triangle(3, 4, 5));
    shapes.push_back(new Square(5));
    shapes.push_back(new Circle(3));
    
    for (const auto shape : shapes) {
        std::cout << "Perimeter: " << shape->perimeter() 
                  << ", Area: " << shape->area() << std::endl;
        delete shape;
    }
    
    return 0;
}
