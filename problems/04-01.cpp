#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <utility>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////

template <typename T, typename Compare = std::less<T>>
void insertion_sort(std::vector<T>& array, std::size_t left, std::size_t right, Compare comp = {})
{
    for (auto i = left + 1; i < right; ++i) 
    {
        auto key = array[i];
        auto j = i;
        
        while (j > left && comp(key, array[j - 1]))
        {
            array[j] = array[j - 1];
            --j;
        }
        
        array[j] = key;
    }
}

////////////////////////////////////////////////////////////////////////////////////

template <typename T, typename Compare = std::less<T>>
void merge(std::vector<T>& array, std::size_t left, std::size_t middle, std::size_t right, Compare comp = {})
{
    auto left_size = middle - left;
    auto right_size = right - middle;
    
    std::vector<T> left_array(array.begin() + left, array.begin() + middle);
    std::vector<T> right_array(array.begin() + middle, array.begin() + right);
    
    std::size_t i = 0, j = 0, k = left;
    
    while (i < left_size && j < right_size) 
    {
        if (!comp(right_array[j], left_array[i])) 
        {
            array[k] = left_array[i++];
        }
        else 
        {
            array[k] = right_array[j++];
        }
        ++k;
    }
    
    while (i < left_size) 
    {
        array[k++] = left_array[i++];
    }
    
    while (j < right_size) 
    {
        array[k++] = right_array[j++];
    }
}

////////////////////////////////////////////////////////////////////////////////////

template <typename T, typename Compare = std::less<T>>
void hybrid_sort(std::vector<T>& array, std::size_t left, std::size_t right, Compare comp = {})
{
    constexpr std::size_t INSERTION_SORT_THRESHOLD = 16;
    
    if (right - left <= INSERTION_SORT_THRESHOLD)
    {
        insertion_sort(array, left, right, comp);
    }
    else
    {
        auto middle = left + (right - left) / 2;
        
        hybrid_sort(array, left, middle, comp);
        hybrid_sort(array, middle, right, comp);
        
        if (comp(array[middle], array[middle - 1]))
        {
            merge(array, left, middle, right, comp);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////

template <typename T, typename Compare = std::less<T>>
void sort(std::vector<T>& array, Compare comp = {})
{
    if (array.empty()) return;
    
    hybrid_sort(array, 0, array.size(), comp);
}

////////////////////////////////////////////////////////////////////////////////////

int main()
{
    std::size_t size = 1000;
    
    std::vector<int> array(size, 0);
    
    for (std::size_t i = 0; i < size; ++i)
    {
        array[i] = static_cast<int>(size - i);
    }
    
    sort(array);
    
    assert(std::is_sorted(array.begin(), array.end()));
    
    return 0;
}
