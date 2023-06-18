#include <iostream>
#include <stdexcept>
#include <string>

template <typename T, size_t size = 256>
class Array
{
    static_assert(0 < size);
    T data[size];

public:
    const size_t length;

    Array() : length(size) {}

    const T &operator[](size_t index) const
    {
        if (length <= index)
        {
            throw std::out_of_range("length=" + std::to_string(length) + ", given index=" + std::to_string(index));
        }
        return data[index];
    }

    T &operator[](size_t index)
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
    Array<int> int_array;
    int_array[0] = 1;
    std::cout << int_array[0] << std::endl;

    Array<double, 1024> double_array;
    double_array[0] = 2.718281828;
    std::cout << double_array[0] << std::endl;

    Array<std::string> string_array;
    string_array[0] = "a";
    std::cout << string_array[0] << std::endl;

    // fail
    // Array<bool, 0> bool_array;

    return 0;
}
