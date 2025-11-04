//////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstddef>
#include <string>
#include <utility>

//////////////////////////////////////////////////////////////////

template <typename... Ts> class Tuple {};

//////////////////////////////////////////////////////////////////

template <typename T, typename... Ts>
class Tuple<T, Ts...> {
public:
    constexpr Tuple() = default;
    template <typename U, typename... Us>
    constexpr Tuple(U&& x, Us&&... ys)
        : m_head(std::forward<U>(x)),
          m_tail(std::forward<Us>(ys)...) {}

    template <std::size_t I>
    constexpr auto get() const {
        if constexpr (I > 0) {
            return m_tail.template get<I - 1>();
        } else {
            return m_head;
        }
    }

    static constexpr std::size_t Size() {
        return 1 + sizeof...(Ts);
    }

private:
    T m_head{};
    Tuple<Ts...> m_tail{};
};

//////////////////////////////////////////////////////////////////

template <>
class Tuple<> {
public:
    constexpr Tuple() = default;

    static constexpr std::size_t Size() {
        return 0;
    }
};

//////////////////////////////////////////////////////////////////

int main() {
    Tuple<int, double, std::string> tuple(1, 2.0, "aaaaa");

    assert(tuple.get<0>() == 1);

    static_assert(Tuple<>::Size() == 0);
    static_assert(Tuple<int>::Size() == 1);
    static_assert(Tuple<int, double>::Size() == 2);
    static_assert(Tuple<int, double, std::string>::Size() == 3);

    assert(tuple.Size() == 3);
}
