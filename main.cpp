#include "sfinae.hpp"
#include "crtp.hpp"

int main()
{
    // Substitution Failure Is Not An Error
    X x;
    test(x, &X::f);
    test(&x, &X::f);
    test(42, 1337);

    std::vector<int> v;
    f(v, v.data(), v.size());

    // Curiously Recurring Template Pattern
}
