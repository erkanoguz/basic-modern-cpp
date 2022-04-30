#ifndef TYPE_TRAITS_IMPL_H
#define TYPE_TRAITS_IMPL_H

namespace exo 
{
    template<typename T>
    struct remove_reference { using type = T; };

    template<typename T>
    struct remove_reference<T&> { using type = T; };

    template <typename T>
    struct remove_reference<T&&> { using type = T; };
}

#endif