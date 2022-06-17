#include "gtest/gtest.h"
#include "../src/type_traits/type_traits_impl.h"

#include <type_traits>
#include <array>

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