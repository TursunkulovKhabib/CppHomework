#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<double> numbers;
    int vectorSize = 0;
    
    std::cout << "Input count of elements" << std::endl;
    std::cin >> vectorSize;
    std::cout << "Input elements" << std::endl;
    for(int i = 0; i < vectorSize; i++) {
        double x = 0;
        std::cin >> x;
        numbers.push_back(x);
    }

    double min = numbers.at(0);
    double max = numbers.at(0);
    double sum = numbers.at(0);
    for (int i = 1; i < vectorSize; i++) {
        min = std::min(numbers.at(i), min);
        max = std::max(numbers.at(i), max);
        sum += numbers[i];
    }
    
    double avg = sum / vectorSize;
    double sigma = 0;
    for (int i = 0; i < vectorSize; i++)
    {
        sigma += (numbers[i] - avg) * (numbers[i] - avg);
    }
    sigma /= (vectorSize > 1 ? vectorSize - 1: 1);
    double deviation = std::sqrt(sigma);
    std::cout << min << " " << max << " " << avg << " " << deviation << std::endl;
}
