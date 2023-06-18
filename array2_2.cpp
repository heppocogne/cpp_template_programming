#include <iostream>
#include <stdexcept>
#include <string>

template <size_t size = 256>
class _PtrArray
{
    static_assert(0 < size);
    void *data[size];

public:
    const size_t length;

    _PtrArray() : length(size) {}

    const void *operator[](size_t index) const
    {
        if (length <= index)
        {
            throw std::out_of_range("length=" + std::to_string(length) + ", given index=" + std::to_string(index));
        }
        return data[index];
    }

    void *&operator[](size_t index)
    {
        if (length <= index)
        {
            throw std::out_of_range("length=" + std::to_string(length) + ", given index=" + std::to_string(index));
        }
        return data[index];
    }
};

template <typename T, size_t size = 256>
class PtrArray : public _PtrArray<size>
{
public:
    const T *operator[](size_t index) const
    {
        return reinterpret_cast<const T *>(_PtrArray<size>::operator[](index));
    }

    T *&operator[](size_t index)
    {
        return reinterpret_cast<T *&>(_PtrArray<size>::operator[](index));
    }
};

int main(void)
{
    PtrArray<int> int_ptr_array;
    int_ptr_array[0] = new int;
    *int_ptr_array[0] = 1;
    std::cout << *int_ptr_array[0] << std::endl;

    PtrArray<double> double_ptr_array;
    *double_ptr_array[0] = 2.718281828;
    std::cout << double_ptr_array[0] << std::endl;

    PtrArray<std::string> string_ptr_array;
    *string_ptr_array[0] = "a";
    std::cout << string_ptr_array[0] << std::endl;

    return 0;
}
