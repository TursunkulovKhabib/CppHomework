#include <iostream>
#include <cmath>

int main() {

    double const epsilon = 0.000000005;

    std::cout << "Input a,b and c: ";

    double a;
    double b;
    double c;
    double x;
    
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    
    if (std::abs(a) <= epsilon) {
        a = 0;
    };

    double discriminant = std::pow(b, 2) - 4 * a * c;

    if (std::abs(discriminant) <= epsilon) {
        discriminant = 0;
    }

    if (discriminant > 0) {
        double firstRoot = (-b - std::pow(discriminant, 0.5)) / (2 * a);
        double secondRoot = (-b + std::pow(discriminant, 0.5)) / (2 * a);
        std::cout << "First x: " << firstRoot << std::endl;
        std::cout << "Second x: " << secondRoot << std::endl;
    } else if (discriminant = 0) {
        double root = -b / (2 * a);
        std::cout << "Root" << root << std::endl;
    } else {
        std::cout << "There are no roots" << std::endl;
    }
    return 0;
}
