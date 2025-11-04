#include <array>
#include <iostream>

consteval double compute_e(double epsilon) {
    double e = 1.0;
    double term = 1.0;
    int n = 1;

    while (true) {
        term /= n;
        if (term < epsilon) break;
        e += term;
        ++n;
    }
    return e;
}

constexpr std::array<double, 5> epsilons = {1.0, 0.5, 0.1, 0.01, 0.001};

constexpr std::array<double, 5> e_values = {
    compute_e(epsilons[0]),
    compute_e(epsilons[1]),
    compute_e(epsilons[2]),
    compute_e(epsilons[3]),
    compute_e(epsilons[4])
};

static_assert(compute_e(1.0) == 2.0);
static_assert(compute_e(0.5) == 2.5);
static_assert(compute_e(0.1) > 2.6 && compute_e(0.1) < 2.7);
static_assert(compute_e(0.01) > 2.7);
static_assert(compute_e(0.001) > compute_e(0.01));

int main() {
    for (size_t i = 0; i < epsilons.size(); ++i) {
        std::cout << "epsilon = " << epsilons[i]
                  << ", e = " << e_values[i] << std::endl;
    }
    return 0;
}
