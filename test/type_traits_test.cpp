#include "gtest/gtest.h"
#include "../src/type_traits/type_traits_impl.h"

class TypeTraitsTest : public ::testing::Test
{};

TEST_F(TypeTraitsTest, TypeTraits_isArray)
{
    int a = 1;
    int b = 1;

    EXPECT_EQ(1, 1);
}