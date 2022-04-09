/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Rect_Test.cpp
** Description: [CHANGE]
*/

#include <gtest/gtest.h>

#include "SW/Utils.hpp"

TEST (Rect, constructor_default)
{
    sw::Rect<int> rect;

    EXPECT_EQ(rect.left, 0);
    EXPECT_EQ(rect.top, 0);
    EXPECT_EQ(rect.width, 0);
    EXPECT_EQ(rect.height, 0);
}

TEST (Rect, constructor_value)
{
    sw::Rect<int> rect(1, 2, 3, 4);

    EXPECT_EQ(rect.left, 1);
    EXPECT_EQ(rect.top, 2);
    EXPECT_EQ(rect.width, 3);
    EXPECT_EQ(rect.height, 4);
}

TEST (Rect, constructor_with_vector)
{
    sw::Vector2i pos(1, 2);
    sw::Vector2i size(3, 4);
    sw::Rect<int> rect(pos, size);

    EXPECT_EQ(rect.left, 1);
    EXPECT_EQ(rect.top, 2);
    EXPECT_EQ(rect.width, 3);
    EXPECT_EQ(rect.height, 4);
}

TEST (Rect, contains)
{
    sw::IntRect rect(0, 0, 10, 10);
    sw::Vector2i point(5, 5);

    EXPECT_TRUE(rect.contains(point));
    EXPECT_TRUE(rect.contains(point.x, point.y));
    point.x = 19;
    EXPECT_FALSE(rect.contains(point));
    EXPECT_FALSE(rect.contains(point.x, point.y));
}

TEST (Rect, intersect)
{
    sw::IntRect rect(0, 0, 10, 10);
    sw::IntRect test1(0, 0, 10, 10);
    sw::IntRect test2(11, 0, 10, 10);
    sw::IntRect test3(5, 0, 10, 10);

    EXPECT_TRUE(rect.intersects(test1));
    EXPECT_FALSE(rect.intersects(test2));
    EXPECT_TRUE(rect.intersects(test3));
}

TEST (Rect, addition)
{
    sw::IntRect rect1(1, 1, 1, 1);
    sw::IntRect rect2(1, 1, 1, 1);

    rect1 = rect1 + rect2;
    EXPECT_EQ(rect1.top, 1);
    EXPECT_EQ(rect1.left, 1);
    EXPECT_EQ(rect1.width, 2);
    EXPECT_EQ(rect1.height, 2);
}

TEST (Rect, equal_addition)
{
    sw::IntRect rect1(1, 1, 1, 1);
    sw::IntRect rect2(1, 1, 1, 1);

    rect1 += rect2;
    EXPECT_EQ(rect1.top, 1);
    EXPECT_EQ(rect1.left, 1);
    EXPECT_EQ(rect1.width, 2);
    EXPECT_EQ(rect1.height, 2);
}

TEST (Rect, substraction)
{
    sw::IntRect rect1(1, 1, 1, 1);
    sw::IntRect rect2(1, 1, 1, 1);

    rect1 = rect1 - rect2;
    EXPECT_EQ(rect1.top, 1);
    EXPECT_EQ(rect1.left, 1);
    EXPECT_EQ(rect1.width, 0);
    EXPECT_EQ(rect1.height, 0);
}

TEST (Rect, equal_substraction)
{
    sw::IntRect rect1(1, 1, 1, 1);
    sw::IntRect rect2(1, 1, 1, 1);

    rect1 -= rect2;
    EXPECT_EQ(rect1.top, 1);
    EXPECT_EQ(rect1.left, 1);
    EXPECT_EQ(rect1.width, 0);
    EXPECT_EQ(rect1.height, 0);
}

TEST (Rect, multiplication)
{
    sw::IntRect rect1(2, 2, 2, 2);
    sw::IntRect rect2(2, 2, 2, 2);

    rect1 = rect1 * rect2;
    EXPECT_EQ(rect1.top, 2);
    EXPECT_EQ(rect1.left, 2);
    EXPECT_EQ(rect1.width, 4);
    EXPECT_EQ(rect1.height, 4);
}

TEST (Rect, equal_multiplication)
{
    sw::IntRect rect1(2, 2, 2, 2);
    sw::IntRect rect2(2, 2, 2, 2);

    rect1 *= rect2;
    EXPECT_EQ(rect1.top, 2);
    EXPECT_EQ(rect1.left, 2);
    EXPECT_EQ(rect1.width, 4);
    EXPECT_EQ(rect1.height, 4);
}

TEST (Rect, division)
{
    sw::IntRect rect1(2, 2, 2, 2);
    sw::IntRect rect2(2, 2, 2, 2);

    rect1 = rect1 / rect2;
    EXPECT_EQ(rect1.top, 2);
    EXPECT_EQ(rect1.left, 2);
    EXPECT_EQ(rect1.width, 1);
    EXPECT_EQ(rect1.height, 1);
}

TEST (Rect, equal_division)
{
    sw::IntRect rect1(2, 2, 2, 2);
    sw::IntRect rect2(2, 2, 2, 2);

    rect1 /= rect2;
    EXPECT_EQ(rect1.top, 2);
    EXPECT_EQ(rect1.left, 2);
    EXPECT_EQ(rect1.width, 1);
    EXPECT_EQ(rect1.height, 1);
}

TEST (Rect, modulo)
{
    sw::IntRect rect1(2, 2, 2, 2);
    sw::IntRect rect2(2, 2, 2, 2);

    rect1 = rect1 % rect2;
    EXPECT_EQ(rect1.top, 2);
    EXPECT_EQ(rect1.left, 2);
    EXPECT_EQ(rect1.width, 0);
    EXPECT_EQ(rect1.height, 0);
}

TEST (Rect, equal_modulo)
{
    sw::IntRect rect1(2, 2, 2, 2);
    sw::IntRect rect2(2, 2, 2, 2);

    rect1 %= rect2;
    EXPECT_EQ(rect1.top, 2);
    EXPECT_EQ(rect1.left, 2);
    EXPECT_EQ(rect1.width, 0);
    EXPECT_EQ(rect1.height, 0);
}

TEST (Rect, equal)
{
    sw::IntRect rect1(1, 1, 1, 1);
    sw::IntRect rect2(1, 1, 1, 1);

    EXPECT_TRUE(rect1 == rect2);
    rect2.height = 9;
    EXPECT_FALSE(rect1 == rect2);
}

TEST (Rect, different)
{
sw::IntRect rect1(1, 1, 1, 1);
    sw::IntRect rect2(1, 1, 1, 1);

    EXPECT_FALSE(rect1 != rect2);
    rect2.height = 9;
    EXPECT_TRUE(rect1 != rect2);
}

TEST (Rect, greater)
{
    sw::IntRect rect1(1, 2, 2, 2);
    sw::IntRect rect2(1, 2, 2, 1);

    EXPECT_TRUE(rect1 > rect2);
    EXPECT_FALSE(rect2 > rect1);
}

TEST (Rect, greater_equal)
{
    sw::IntRect rect1(1, 2, 2, 2);
    sw::IntRect rect2(1, 2, 2, 1);

    EXPECT_TRUE(rect1 >= rect2);
    EXPECT_FALSE(rect2 >= rect1);
    rect2.height = 2;
    EXPECT_TRUE(rect1 >= rect2);
}

TEST (Rect, less)
{
    sw::IntRect rect1(1, 2, 2, 2);
    sw::IntRect rect2(1, 2, 2, 3);

    EXPECT_TRUE(rect1 < rect2);
    EXPECT_FALSE(rect2 < rect1);
}

TEST (Rect, less_equal)
{
    sw::IntRect rect1(1, 2, 2, 2);
    sw::IntRect rect2(1, 2, 2, 3);

    EXPECT_TRUE(rect1 <= rect2);
    EXPECT_FALSE(rect2 <= rect1);
    rect2.height = 2;
    EXPECT_TRUE(rect1 <= rect2);
}