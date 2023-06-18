#include <iostream>

template <unsigned long long i>
struct Factorial
{
    static constexpr unsigned long long value = i * Factorial<i - 1>::value;
};

template <>
struct Factorial<1>
{
    static constexpr unsigned long long value = 1;
};

template <>
struct Factorial<0>
{
    static constexpr unsigned long long value = 0;
};

int main(void)
{
    std::cout << "factorial(0)=" << Factorial<0>::value << std::endl;
    std::cout << "factorial(1)=" << Factorial<1>::value << std::endl;

    std::cout << "factorial(4)=" << Factorial<4>::value << std::endl;
    std::cout << "factorial(5)=" << Factorial<5>::value << std::endl;

    std::cout << "factorial(9)=" << Factorial<9>::value << std::endl;
    std::cout << "factorial(10)=" << Factorial<10>::value << std::endl;

    return 0;
}