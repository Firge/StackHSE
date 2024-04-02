#include "StackArr/StackArr.hpp"
#include <gtest/gtest.h>

TEST(StackTest, PushPop) {
    StackArr<int> s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.top(), 2);
    s.pop();
    EXPECT_EQ(s.top(), 1);
    s.pop();
    EXPECT_TRUE(s.empty());
}

TEST(StackTest, Empty) {
    StackArr<int> s;
    EXPECT_TRUE(s.empty());
    s.push(1);
    EXPECT_FALSE(s.empty());
}

TEST(StackTest, Copy) {
    StackArr<int> s1;
    s1.push(1);
    s1.push(2);
    StackArr<int> s2(s1);
    EXPECT_EQ(s2.top(), 2);
    s2.pop();
    EXPECT_EQ(s2.top(), 1);
    EXPECT_EQ(s1.top(), 2);
}

TEST(StackTest, Move) {
    StackArr<int> s1;
    s1.push(1);
    s1.push(2);

    StackArr<int> s2(std::move(s1));
    EXPECT_EQ(s2.top(), 2);
    s2.pop();
    EXPECT_EQ(s2.top(), 1);
    EXPECT_TRUE(s1.empty());
}
