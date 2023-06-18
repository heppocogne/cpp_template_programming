#include <iostream>
#include <stdexcept>
#include <string>

template <typename T, size_t size = 256>
class PtrArray
{
    static_assert(0 < size);
    T *data[size];

public:
    const size_t length;

    PtrArray() : length(size) {}

    const T *operator[](size_t index) const
    {
        if (length <= index)
        {
            throw std::out_of_range("length=" + std::to_string(length) + ", given index=" + std::to_string(index));
        }
        return data[index];
    }

    T *&operator[](size_t index)
    {
        if (length <= index)
        {
            throw std::out_of_range("length=" + std::to_string(length) + ", given index=" + std::to_string(index));
        }
        return data[index];
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
