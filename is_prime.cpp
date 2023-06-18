#include <iostream>

template <unsigned long long i>
struct IsPrime
{
    constexpr const static bool value = (MultiplyRemainders<i, i - 1>::value != 0);
};

template <>
struct IsPrime<0>
{
    constexpr const static bool value = false;
};

template <>
struct IsPrime<1>
{
    constexpr const static bool value = false;
};

template <>
struct IsPrime<2>
{
    constexpr const static bool value = true;
};

template <unsigned long long a, unsigned long long b>
struct MultiplyRemainders
{
    constexpr const static unsigned long long value = (a % b) * MultiplyRemainders<a, b - 1>::value;
};

template <unsigned long long a>
struct MultiplyRemainders<a, 2>
{
    constexpr const static unsigned long long value = a % 2;
};

int main(void)
{
    std::cout << "is_prime(2)=" << IsPrime<2>::value << std::endl;
    std::cout << "is_prime(3)=" << IsPrime<3>::value << std::endl;
    std::cout << "is_prime(4)=" << IsPrime<4>::value << std::endl;
    std::cout << "is_prime(5)=" << IsPrime<5>::value << std::endl;
    std::cout << "is_prime(7)=" << IsPrime<7>::value << std::endl;
    std::cout << "is_prime(9)=" << IsPrime<9>::value << std::endl;
    std::cout << "is_prime(11)=" << IsPrime<11>::value << std::endl;
    std::cout << "is_prime(13)=" << IsPrime<13>::value << std::endl;
    std::cout << "is_prime(15)=" << IsPrime<15>::value << std::endl;
    std::cout << "is_prime(17)=" << IsPrime<17>::value << std::endl;
    std::cout << "is_prime(19)=" << IsPrime<19>::value << std::endl;
    std::cout << "is_prime(21)=" << IsPrime<21>::value << std::endl;
    std::cout << "is_prime(23)=" << IsPrime<23>::value << std::endl;
    std::cout << "is_prime(25)=" << IsPrime<25>::value << std::endl;
    std::cout << "is_prime(27)=" << IsPrime<27>::value << std::endl;
    std::cout << "is_prime(29)=" << IsPrime<29>::value << std::endl;

    return 0;
}