#include <numbers>

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double perimeter() const {
        return side1 + side2 + side3;
    }

    double area() const {
        double p = perimeter() / 2;
        return p * (p - side1) * (p - side2) * (p - side3);
    }
};

class Square {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double perimeter() const {
        return 4 * side;
    }

    double area() const {
        return side * side;
    }
};

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double perimeter() const {
        return 2 * std::numbers::pi * radius;
    }

    double area() const {
        return std::numbers::pi * radius * radius;
    }
};
