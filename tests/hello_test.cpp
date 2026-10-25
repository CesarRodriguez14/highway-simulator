#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions){
    EXPECT_STRNE("hello","world");
    EXPECT_EQ(7*8,56);
}