////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <utility>

////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Vector
{
private:

    T * m_array = nullptr;

    std::size_t m_capacity = 0;

    std::size_t m_size = 0;

public :

	Vector() : m_array(nullptr), m_size(0)
	{
		std::cout << "Vector:: Vector (1)\n";
	}

//  --------------------------------------------------------------------------------

	Vector(std::initializer_list <T> list) : m_size(std::size(list))
	{
		std::cout << "Vector:: Vector (2)\n";

		m_array = m_size ? new T[m_size]{} : nullptr;

		std::copy(list.begin(), list.end(), m_array);
	}

//  --------------------------------------------------------------------------------

	Vector(Vector const & other) : m_size(other.m_size)
	{
		std::cout << "Vector:: Vector (3)\n";

		m_array = m_size ? new T[m_size]{} : nullptr;

		std::copy(other.m_array, other.m_array + other.m_size, m_array);
	}

//  --------------------------------------------------------------------------------

	Vector(Vector && other)
	:
		m_array(std::exchange(other.m_array, nullptr)),

		m_size (std::exchange(other.m_size,  0      ))
	{
		std::cout << "Vector:: Vector (4)\n";
	}

//  --------------------------------------------------------------------------------

   ~Vector()
	{
		std::cout << "Vector::~Vector\n";

		delete[] m_array;
	}
	
//  --------------------------------------------------------------------------------

//	auto & operator=(Vector const & other) // error
//	{
//		std::cout << "Vector::operator= (1)\n";
//
//		if (this != &other)
//		{
//			delete[] m_array;
//
//			m_array = (m_size = other.m_size) ? new T[m_size]{} : nullptr;
//
//			std::copy(other.m_array, other.m_array + other.m_size, m_array);
//		}
//
//		return *this;
//	}

//  --------------------------------------------------------------------------------

//	auto & operator=(Vector const & other) // bad
//	{
//		std::cout << "Vector::operator= (2)\n";
//
//		if (this != &other)
//		{
//			auto array = other.m_size ? new T[other.m_size]{} : nullptr;
//
//			std::copy(other.m_array, other.m_array + other.m_size, array);
//
//			delete[] std::exchange(m_array, array);
//
//			m_size = other.m_size;
//		}
//
//		return *this;
//	}

//  --------------------------------------------------------------------------------

//	auto & operator=(Vector && other) // bad
//	{
//		std::cout << "Vector::operator= (3)\n";
//
//		if (this != &other)
//		{
//			delete[] m_array;
//
//			m_array = std::exchange(other.m_array, nullptr);
//
//			m_size  = std::exchange(other.m_size,  0      );
//		}
//
//		return *this;
//	}

//  --------------------------------------------------------------------------------

	auto & operator=(Vector other)
	{
		std::cout << "Vector::operator= (4)\n";

		swap(other);

		return *this;
	}

//  --------------------------------------------------------------------------------

	void swap(Vector & other)
	{
		std::swap(m_array, other.m_array);

		std::swap(m_size,  other.m_size );
	}

//  --------------------------------------------------------------------------------

    std::size_t capacity() const
    {
        return m_capacity;
    }

//  --------------------------------------------------------------------------------

    std::size_t size() const
    {
        return m_size;
    }

//  --------------------------------------------------------------------------------

    bool empty() const
    {
        return m_size == 0;
    }

//  --------------------------------------------------------------------------------

    void push_back(T const & value)
    {
        if (m_size == m_capacity)
        {
            std::size_t new_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
            
            T * new_array = new T[new_capacity]{};
            
            if (m_array)
            {
                std::copy(m_array, m_array + m_size, new_array);
                
                delete[] m_array;
            }
            
            m_array = new_array;
            
            m_capacity = new_capacity;
        }
        
        m_array[m_size] = value;
        
        ++m_size;
    }

//  --------------------------------------------------------------------------------

    void clear()
    {
        m_size = 0;
    }
};

////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void swap(Vector<T> & lhs, Vector<T> & rhs)
{
	lhs.swap(rhs);
}

////////////////////////////////////////////////////////////////////////////////////

int main()
{
   // Old strings
   Vector<int> vector_1;

   Vector<int> vector_2 = { 1, 2, 3, 4, 5 };

   Vector<int> vector_3 = vector_2;

   Vector<int> vector_4 = std::move(vector_3);

   vector_3 = vector_2;

   vector_4 = std::move(vector_3);

   swap(vector_1, vector_2);

   // Tests
   Vector<int> v;
   assert(v.size() == 0);
   assert(v.capacity() == 0);
   assert(v.empty() == true);

   v.push_back(1);
   assert(v.size() == 1);
   assert(v.capacity() == 1);
   assert(v.empty() == false);

   v.push_back(2);
   assert(v.size() == 2);
   assert(v.capacity() == 2);

   v.push_back(3);
   assert(v.size() == 3);
   assert(v.capacity() == 4);

   v.clear();
   assert(v.size() == 0);
   assert(v.capacity() == 4);
   assert(v.empty() == true);
}

////////////////////////////////////////////////////////////////////////////////////
