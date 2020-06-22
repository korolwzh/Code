#include "Hailstone.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;
using namespace sequence;

TEST(HailstoneTests, testsatisfiesHailstone)
{
    int zero = 0;
    ASSERT_EQ(false, satisfiesHailstone(zero));
    int one = 1; 
    ASSERT_EQ(true, satisfiesHailstone(one));
    int two = 2;
    ASSERT_EQ(true, satisfiesHailstone(two));
    int three = 3;
    ASSERT_EQ(true, satisfiesHailstone(three));
}