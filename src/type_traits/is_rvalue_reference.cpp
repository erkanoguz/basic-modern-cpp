#include <iostream>
#include "type_traits_impl.h"


class A{};

int main() 
{
    A a;
    std::cout << std::boolalpha;
    std::cout << exo::is_rvalue_reference_v<int>  << "\n";
    std::cout << exo::is_rvalue_reference_v<int&> << "\n";
    std::cout << exo::is_rvalue_reference_v<int&&> << "\n";
}