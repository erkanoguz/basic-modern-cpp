#include <iostream>
#include <type_traits>
#include "type_traits_impl.h"

int main() 
{   
    std::cout << std::boolalpha;
    std::cout << std::is_same<std::remove_reference<int>::type, exo::remove_reference<int>::type>::value << "\n";;
    std::cout << std::is_same<std::remove_reference<int&>::type, exo::remove_reference<int&>::type>::value << "\n";
    std::cout << std::is_same<std::remove_reference<int&&>::type, exo::remove_reference<int&&>::type>::value << "\n";
    std::cout << std::is_same<std::remove_reference<const int&>::type, exo::remove_reference<const int&>::type>::value << "\n";
}