#include <type_traits>
#include <utility>

template<typename... Args>
double max_value(Args&&... args) {
    double result = 0;
    bool first = true;
    
    auto update_max = [&](double value) {
        if (first) {
            result = value;
            first = false;
        } else if (value > result) {
            result = value;
        }
    };
    
    ( ... , (std::is_same_v<std::decay_t<Args>, double> ? update_max(args) : (void)0) );
    
    return result;
}

template<typename... Args>
double min_value(Args&&... args) {
    double result = 0;
    bool first = true;
    
    auto update_min = [&](double value) {
        if (first) {
            result = value;
            first = false;
        } else if (value < result) {
            result = value;
        }
    };
    
    ( ... , (std::is_same_v<std::decay_t<Args>, double> ? update_min(args) : (void)0) );
    
    return result;
}

template<typename... Args>
double sum(Args&&... args) {
    double result = 0;
    
    auto add_value = [&](double value) {
        result += value;
    };
    
    ( ... , (std::is_same_v<std::decay_t<Args>, double> ? add_value(args) : (void)0) );
    
    return result;
}

template<typename... Args>
double average(Args&&... args) {
    double total = 0;
    size_t count = 0;
    
    auto add_value = [&](double value) {
        total += value;
        ++count;
    };
    
    ( ... , (std::is_same_v<std::decay_t<Args>, double> ? add_value(args) : (void)0) );
    
    return total / count;
}

template<typename... Args>
double max_value_double(Args&&... args) {
    return max_value(std::forward<Args>(args)...);
}

template<typename... Args>
double min_value_double(Args&&... args) {
    return min_value(std::forward<Args>(args)...);
}

template<typename... Args>
double sum_double(Args&&... args) {
    return sum(std::forward<Args>(args)...);
}

template<typename... Args>
double average_double(Args&&... args) {
    return average(std::forward<Args>(args)...);
}
