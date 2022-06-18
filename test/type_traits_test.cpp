#include "gtest/gtest.h"
#include "../src/type_traits/type_traits_impl.h"

#include <type_traits>
#include <array>
#include <memory>

class TypeTraitsTest : public ::testing::Test
{};

class A {};

TEST_F(TypeTraitsTest, TypeTraits_isArray)
{
    EXPECT_FALSE(exo::is_array<A>::value);
    EXPECT_EQ(std::is_array<A>::value, exo::is_array<A>::value);
    EXPECT_TRUE(exo::is_array<A[]>::value);
    EXPECT_EQ(std::is_array<A[]>::value, exo::is_array<A[]>::value);
    EXPECT_FALSE(exo::is_array<float>::value);
    EXPECT_FALSE(exo::is_array<int>::value);
    EXPECT_TRUE(exo::is_array<int[]>::value);
    constexpr bool stdArray = std::is_array<std::array<int, 3>>::value;
    constexpr bool exoArray = exo::is_array<std::array<int, 3>>::value;
    EXPECT_EQ(stdArray, exoArray);
}

TEST_F(TypeTraitsTest, TypeTraits_isPointer)
{
    EXPECT_FALSE(exo::is_pointer<A>::value);
    EXPECT_FALSE(exo::is_pointer_v<A>);
    EXPECT_EQ(std::is_pointer<A*>::value, exo::is_pointer<A*>::value);
    EXPECT_EQ(std::is_pointer<A const*>::value, exo::is_pointer<A const*>::value);
    EXPECT_TRUE(exo::is_pointer_v<A*>);
}

TEST_F(TypeTraitsTest, TypeTraits_isSame)
{
    auto stdIsSame = std::is_same<int, uint32_t>::value;
    auto exoIsSame = exo::is_same<int, uint32_t>::value;
    auto trueIsSame = exo::is_same<A, A>::value;
    auto constIsSame = exo::is_same<const int, int>::value;
    std::unique_ptr<const int> cv{new int(10)};
    std::unique_ptr<int> v{new int(10)};
    auto up = exo::is_same_v<decltype(cv), decltype(v)>;

    EXPECT_EQ(stdIsSame, exoIsSame);
    EXPECT_TRUE(trueIsSame);
    EXPECT_FALSE(constIsSame);
    EXPECT_FALSE(up);
}