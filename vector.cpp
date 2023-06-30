#include <iostream>

using int_t = int;
using real_t = float;

template <typename A, typename B>
struct PreciseType
{
    using type = real_t;
};

template <>
struct PreciseType<int_t, int_t>
{
    using type = int_t;
};

template <typename T, int n>
struct Vector
{
private:
    template <typename Arg0, typename... Args>
    void set_values(int index, Arg0 arg0, Args... args)
    {
        elem[index] = arg0;
        set_values<Args...>(index + 1, args...);
    }

    template <typename Arg0>
    void set_values(int index, Arg0 arg0)
    {
        elem[index] = arg0;
    }

public:
    Vector()
    {
        for (int i = 0; i < n; i++)
        {
            elem[i] = 0;
        }
    }

    template <typename... Args>
    Vector(Args... args)
    {
        static_assert(sizeof...(args) == n);
        set_values<Args...>(0, args...);
    }

    template <typename ArgType>
    Vector(const Vector<ArgType, n> &other)
    {
        for (int i = 0; i < n; i++)
        {
            elem[i] = other.elem[i];
        }
    }

    T elem[n];

    Vector<T, n> operator-()
    {
        Vector<T, n> v;
        for (int i = 0; i < n; i++)
        {
            v.elem[i] = -elem[i];
        }
        return v;
    }

    template <typename T2>
    Vector<typename PreciseType<T, T2>::type, n> operator+(const Vector<T2, n> &right)
    {
        Vector<typename PreciseType<T, T2>::type, n> r;
        for (int i = 0; i < n; i++)
        {
            r.elem[i] = elem[i] + right.elem[i];
        }
        return r;
    }

    template <typename T2>
    Vector<typename PreciseType<T, T2>::type, n> operator-(const T2 &right)
    {
        return *this + (-right);
    }

    template <typename T2>
    Vector<typename PreciseType<T, T2>::type, n> operator*(const T2 &right)
    {
        Vector<typename PreciseType<T, T2>::type, n> r;
        for (int i = 0; i < n; i++)
        {
            r.elem[i] = elem[i] * right;
        }
        return r;
    }

    template <typename T2>
    Vector<typename PreciseType<T, T2>::type, n> operator/(const T2 &right)
    {
        Vector<typename PreciseType<T, T2>::type, n> r;
        for (int i = 0; i < n; i++)
        {
            r.elem[i] = elem[i] / right;
        }
        return r;
    }
};

template <typename T, int n>
std::ostream &operator<<(std::ostream &ost, Vector<T, n> v)
{
    ost << "(";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            ost << v.elem[i] << ")";
        }
        else
        {
            ost << v.elem[i] << ", ";
        }
    }
    return ost;
}

template <typename R, typename A, int n, typename T>
R operator*(const A &left, const Vector<T, n> &right)
{
    return right * left;
}

int main()
{
    std::cout << Vector<real_t, 2>(0.1, 0.2) + Vector<int_t, 2>(1, 2) << std::endl;
    std::cout << Vector<real_t, 3>(0.1, 0.2, 0.3) * 10 << std::endl;

    return 0;
}