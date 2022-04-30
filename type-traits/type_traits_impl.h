#ifndef TYPE_TRAITS_IMPL_H
#define TYPE_TRAITS_IMPL_H

namespace exo {

    template<typename T> struct remove_reference { using type = T; };
    template<typename T> struct remove_reference<T&> { using type = T; };
    template <typename T> struct remove_reference<T&&> { using type = T; };

    template<typename T>
    typename exo::remove_reference<T>::type&& move(T&& arg)
    {
        return static_cast<exo::remove_reference<T>::type&&>(args);
    }   
}


#endif