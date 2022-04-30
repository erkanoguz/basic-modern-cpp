#include <iostream>
#include <type_traits>


namespace exo 
{
    template<typename T>
    struct remove_reference { using type = T; };

    template<typename T>
    struct remove_reference<T&> { using type = T; };

    template <typename T>
    struct remove_reference<T&&> { using type = T; };
}


int main() 
{   
    std::cout << std::boolalpha;
    std::cout << std::is_same<std::remove_reference<int>::type, exo::remove_reference<int>::type>::value << "\n";;
    std::cout << std::is_same<std::remove_reference<int&>::type, exo::remove_reference<int&>::type>::value << "\n";
    std::cout << std::is_same<std::remove_reference<int&&>::type, exo::remove_reference<int&&>::type>::value << "\n";
    std::cout << std::is_same<std::remove_reference<const int&>::type, exo::remove_reference<const int&>::type>::value << "\n";
}