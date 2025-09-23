#include <iostream>
#include <vector>
#include <cmath>

std::size_t collatz(unsigned long long int n, std::vector<std::size_t>& cache);

int main() {
    const std::size_t max_start = 100;
    const std::size_t cache_size = 1000000;
    
    std::vector<std::size_t> cache(cache_size, 0);
    cache[1] = 1;
    
    std::size_t maxLength = 0;
    std::size_t maxStartValue = 1;
    

    for (std::size_t start = 1; start <= max_start; ++start) {
        std::size_t length = collatz(start, cache);

        if (length > maxLength) {
            maxLength = length;
            maxStartValue = start;
        }
    }
    
    std::cout << maxStartValue << " " << maxLength << std::endl;
    return 0;
}

std::size_t collatz(unsigned long long int n, std::vector<std::size_t>& cache) {
    if (n < cache.size() && cache[n] != 0) {
        return cache[n];
    }
    
    unsigned long long int next;
    if (n % 2 == 0) {
        next = n / 2;
    } else {
        next = 3 * n + 1;
    }
    
    std::size_t length = 1 + collatz(next, cache);
    
    if (n < cache.size()) {
        cache[n] = length;
    }
    
    return length;
}

