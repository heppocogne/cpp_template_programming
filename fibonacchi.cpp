#include <iostream>

template <unsigned long long i>
struct Fibonacchi
{
    static constexpr unsigned long long value = Fibonacchi<i - 1>::value + Fibonacchi<i - 2>::value;
};

template <>
struct Fibonacchi<0>
{
    static constexpr unsigned long long value = 0;
};

template <>
struct Fibonacchi<1>
{
    static constexpr unsigned long long value = 1;
};

int main(void)
{
    std::cout << "fibonacchi(0)=" << Fibonacchi<0>::value << std::endl;
    std::cout << "fibonacchi(0)=" << Fibonacchi<1>::value << std::endl;

    std::cout << "fibonacchi(10)=" << Fibonacchi<10>::value << std::endl;
    std::cout << "fibonacchi(11)=" << Fibonacchi<11>::value << std::endl;
    std::cout << "fibonacchi(12)=" << Fibonacchi<12>::value << std::endl;

    std::cout << "fibonacchi(100)=" << Fibonacchi<100>::value << std::endl;
    std::cout << "fibonacchi(101)=" << Fibonacchi<101>::value << std::endl;
    std::cout << "fibonacchi(102)=" << Fibonacchi<102>::value << std::endl;

    return 0;
}