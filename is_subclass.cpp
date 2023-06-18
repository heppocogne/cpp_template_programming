class BaseClass
{
};

class InheritClass : public BaseClass
{
};

class OtherClass
{
};

template <typename T1, typename T2>
struct IsSubClass
{
    static void evaluate()
    {
        T2 *ptr = static_cast<T1 *>(0);
    }
};

int main(void)
{
    IsSubClass<InheritClass, BaseClass>::evaluate();

    // fail
    // IsSubClass<OtherClass, BaseClass>::evaluate();

    return 0;
}