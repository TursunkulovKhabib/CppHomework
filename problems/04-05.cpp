#include <limits>

template<int N>
struct Fibonacci {
    static_assert(N > 0, "N must be positive");
    static_assert(N <= 46, "N is too large, overflow may occur");
    static const int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<1> {
    static const int value = 1;
};

template<>
struct Fibonacci<2> {
    static const int value = 1;
};

template<int N>
const int fibonacci_v = Fibonacci<N>::value;

// Tests
static_assert(fibonacci_v<1> == 1);
static_assert(fibonacci_v<2> == 1);
static_assert(fibonacci_v<3> == 2);
static_assert(fibonacci_v<4> == 3);
static_assert(fibonacci_v<5> == 5);
static_assert(fibonacci_v<6> == 8);
static_assert(fibonacci_v<7> == 13);
static_assert(fibonacci_v<8> == 21);
static_assert(fibonacci_v<9> == 34);
static_assert(fibonacci_v<10> == 55);

int main() {
    return 0;
}
