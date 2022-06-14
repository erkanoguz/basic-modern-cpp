#ifndef TYPE_TRAITS_IMPL_H
#define TYPE_TRAITS_IMPL_H

namespace exo {

    template <typename T, T v>
    struct integral_constant {
        static constexpr T value = v;
        using value_type = T;
        using type = integral_constant;
        constexpr operator value_type() const noexcept { return value; }
        constexpr value_type operator() () { return value; }
    };

    template <bool B>
    using bool_constant = integral_constant<bool, B>;
    using false_type = bool_constant<false>;
    using true_type = bool_constant<true>;


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

    template <typename T>
    struct is_pointer : false_type {};

    template <typename T>
    struct is_pointer<T*> : true_type {};

    template <typename T>
    struct is_pointer<T* const> : true_type {};
    
    template<typename T>
    inline constexpr bool is_pointer_v = is_pointer<T>::value;
}


#endif