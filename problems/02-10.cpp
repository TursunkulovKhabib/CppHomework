#include <algorithm>
#include <cassert>
#include <cstddef>
#include <utility>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////

void insertion_sort(std::vector<int>& array, std::size_t left, std::size_t right)
{
    for (auto i = left + 1; i < right; ++i) 
    {
        auto key = array[i];
        auto j = i;
        
        while (j > left && array[j - 1] > key)
        {
            array[j] = array[j - 1];
            --j;
        }
        
        array[j] = key;
    }
}

////////////////////////////////////////////////////////////////////////////////////

void merge(std::vector<int>& array, std::size_t left, std::size_t middle, std::size_t right)
{
    auto left_size = middle - left;
    auto right_size = right - middle;
    
    std::vector<int> left_array(array.begin() + left, array.begin() + middle);
    std::vector<int> right_array(array.begin() + middle, array.begin() + right);
    
    std::size_t i = 0, j = 0, k = left;
    
    while (i < left_size && j < right_size) 
    {
        if (left_array[i] <= right_array[j]) 
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

void hybrid_sort(std::vector<int>& array, std::size_t left, std::size_t right)
{
    constexpr std::size_t INSERTION_SORT_THRESHOLD = 16;
    
    if (right - left <= INSERTION_SORT_THRESHOLD)
    {
        insertion_sort(array, left, right);
    }
    else
    {
        auto middle = left + (right - left) / 2;
        
        hybrid_sort(array, left, middle);
        hybrid_sort(array, middle, right);
        
        if (array[middle - 1] > array[middle])
        {
            merge(array, left, middle, right);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////

void sort(std::vector<int>& array)
{
    if (array.empty()) return;
    
    hybrid_sort(array, 0, array.size());
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
