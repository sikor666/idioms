#pragma once

#include <iostream>
#include <vector>

// this overload is always in the set of overloads
// ellipsis parameter has the lowest ranking for overload resolution
void test(...)
{
    std::cout << "Catch-all overload called\n";
}

// this overload is added to the set of overloads if
// C is a reference-to-class type and F is a pointer to member function of C
template <class C, class F>
auto test(C c, F f) -> decltype((void)(c.*f)(), void())
{
    std::cout << "Reference overload called\n";
}

// this overload is added to the set of overloads if
// C is a pointer-to-class type and F is a pointer to member function of C
template <class C, class F>
auto test(C c, F f) -> decltype((void)((c->*f)()), void())
{
    std::cout << "Pointer overload called\n";
}

struct X { void f() {} };

template<typename Iter>
typename Iter::value_type mean(Iter first, Iter last)
{
    std::cout << "Call when iterators have value_type member\n";

    return Iter::value_type{};
}

template<typename T>
T* mean(T*, T*)
{
    std::cout << "For example, int* hasn't value_type member\n";

    return {};
}

void f(std::vector<int>& v, int* p, int n)
{
    auto x = mean(v.begin(), v.end());
    auto y = mean(p, p + n);
}
