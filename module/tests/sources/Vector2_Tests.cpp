/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Vector2_Tests.cpp
** Description: [CHANGE]
*/

#include <gtest/gtest.h>

#include "utils/Vector2.hpp"

TEST (Vector2, contructor_default)
{
    sw::Vector2<int> vector2;

    EXPECT_EQ(vector2.x, 0);
    EXPECT_EQ(vector2.y, 0);
}

TEST (Vector2, contructor_value)
{
    sw::Vector2<int> vector2(2, 4);

    EXPECT_EQ(vector2.x, 2);
    EXPECT_EQ(vector2.y, 4);
}

TEST (Vector2, subsraction)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(1, 1);

    vector2 = vector2 - vector3;

    EXPECT_EQ(vector2.x, 1);
    EXPECT_EQ(vector2.y, 1);
}

TEST (Vector2, equal_subsraction)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(1, 1);

    vector2 -= vector3;

    EXPECT_EQ(vector2.x, 1);
    EXPECT_EQ(vector2.y, 1);
}

TEST (Vector2, opposite)
{
    sw::Vector2<int> vector2(2, 2);

    vector2 = -vector2;

    EXPECT_EQ(vector2.x, -2);
    EXPECT_EQ(vector2.y, -2);
}

TEST (Vector2, addition)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(1, 1);

    vector2 = vector2 + vector3;

    EXPECT_EQ(vector2.x, 3);
    EXPECT_EQ(vector2.y, 3);
}

TEST (Vector2, equal_addition)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(1, 1);

    vector2 += vector3;

    EXPECT_EQ(vector2.x, 3);
    EXPECT_EQ(vector2.y, 3);
}

TEST (Vector2, multiplication)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(2, 2);

    vector2 = vector2 * vector3;

    EXPECT_EQ(vector2.x, 4);
    EXPECT_EQ(vector2.y, 4);
}

TEST (Vector2, equal_multiplication)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(2, 2);

    vector2 *= vector3;

    EXPECT_EQ(vector2.x, 4);
    EXPECT_EQ(vector2.y, 4);
}

TEST (Vector2, multiplication_by_two)
{
    sw::Vector2<int> vector2(2, 2);

    vector2 = vector2 * 2;

    EXPECT_EQ(vector2.x, 4);
    EXPECT_EQ(vector2.y, 4);
}

TEST (Vector2, equal_multiplication_by_two)
{
    sw::Vector2<int> vector2(2, 2);

    vector2 *= 2;

    EXPECT_EQ(vector2.x, 4);
    EXPECT_EQ(vector2.y, 4);
}

TEST (Vector2, division)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(2, 2);

    vector2 = vector2 / vector3;

    EXPECT_EQ(vector2.x, 1);
    EXPECT_EQ(vector2.y, 1);
}

TEST (Vector2, equal_division)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(2, 2);

    vector2 /= vector3;

    EXPECT_EQ(vector2.x, 1);
    EXPECT_EQ(vector2.y, 1);
}

TEST (Vector2, division_by_two)
{
    sw::Vector2<int> vector2(2, 2);

    vector2 = vector2 / 2;

    EXPECT_EQ(vector2.x, 1);
    EXPECT_EQ(vector2.y, 1);
}

TEST (Vector2, equal_division_by_two)
{
    sw::Vector2<int> vector2(2, 2);

    vector2 /= 2;

    EXPECT_EQ(vector2.x, 1);
    EXPECT_EQ(vector2.y, 1);
}

TEST (Vector2, equal)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(2, 2);

    EXPECT_TRUE(vector2 == vector3);
    vector2.x = 7;
    EXPECT_FALSE(vector2 == vector3);
}

TEST (Vector2, different)
{
    sw::Vector2<int> vector2(2, 2);
    sw::Vector2<int> vector3(2, 2);

    EXPECT_FALSE(vector2 != vector3);
    vector2.x = 7;
    EXPECT_TRUE(vector2 != vector3);
}

TEST (Vector2, display)
{
    sw::Vector2<int> vector2(1, 1);

    testing::internal::CaptureStdout();
    std::cout << vector2;
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "Vector<i> : [ x:1 , y:1 ]\n");
}