#include <iostream>

template <int n = 1>
struct One
{
    static const constexpr long double value = One<n - 1>::value / 2.0 + 0.5;
};

template <>
struct One<0>
{
    static const constexpr long double value = 0;
};

template <int n = 1>
struct Two
{
    static const constexpr long double value = Two<n - 1>::value / 2.0 + 1.0;
};

template <>
struct Two<0>
{
    static const constexpr long double value = 0;
};

int main(void)
{
    std::cout << One<400>::value << std::endl;
    std::cout << Two<400>::value << std::endl;

    return 0;
}