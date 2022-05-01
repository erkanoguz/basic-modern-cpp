#include "type_traits_impl.h"
#include <iostream>
#include <type_traits>

int main() 
{
    using Type1 = exo::conditional<true, int, double>::type;
    using Type2 = exo::conditional<false, double, int>::type;

    std::cout << typeid(Type1).name() << "\n";
    std::cout << typeid(Type2).name() << "\n";
}