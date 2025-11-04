#include <vector>

template<typename Container, typename... Args>
void add_all(Container& container, Args... args) {
    (container.push_back(args), ...);
}

int main() {
    std::vector<int> vec;
    add_all(vec, 1, 2, 3, 4, 5);
    return 0;
}
