#ifndef TYPE_TRAITS_IMPL_H
#define TYPE_TRAITS_IMPL_H

namespace exo {

    struct false_type 
    {
        static constexpr bool value = false;
        constexpr operator bool() const noexcept { return value; }
    };

    struct true_type 
    {
        static constexpr bool value = true;
        constexpr operator bool() const noexcept { return value; }
    };


    template<typename T> struct remove_reference { using type = T; };
    template<typename T> struct remove_reference<T&> { using type = T; };
    template <typename T> struct remove_reference<T&&> { using type = T; };

    template <typename T> 
    using remove_reference_t = typename remove_reference<T>::type;

    template<typename T>
    typename remove_reference<T>::type&& move(T&& arg)
    {
        return static_cast<typename remove_reference<T>::type&&>(arg);
    }

    template <bool B, typename T, typename F> struct conditional { using type = T; };
    template <typename T, typename F> struct conditional<false, T, F>  { using type = F; }; 
    
    template <bool B, typename T, typename F>
    using conditional_t = typename conditional<B,T,F>::type;

    template <typename T> struct is_rvalue_reference : false_type {};
    template <typename T> struct is_rvalue_reference<T&&> : true_type {};
    template <typename T> 
    constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;
}


#endif