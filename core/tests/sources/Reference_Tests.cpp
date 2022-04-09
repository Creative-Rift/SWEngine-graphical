/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Reference_Tests.cpp
** Description: [CHANGE]
*/

#include <gtest/gtest.h>

#include "SW/Utils.hpp"

TEST (Reference, constructor_default)
{
    sw::Reference<int> ref;

    EXPECT_FALSE(ref.hasValue());
}

TEST (Reference, constructor_value)
{
    int value = 3;
    sw::Reference<int> ref(value);

    EXPECT_TRUE(ref.hasValue());
    EXPECT_EQ(*ref, 3);
}

TEST (Reference, emplace)
{
    int value = 3;
    int new_value = 5;
    sw::Reference<int> ref(value);

    EXPECT_TRUE(ref.hasValue());
    EXPECT_EQ(*ref, 3);
    ref.emplace(new_value);
    EXPECT_EQ(*ref, 5);
}

TEST (Reference, equal)
{
    int value = 3;
    int new_value = 5;
    sw::Reference<int> ref(value);

    EXPECT_TRUE(ref.hasValue());
    EXPECT_EQ(*ref, 3);
    ref = new_value;
    EXPECT_EQ(*ref, 5);
}

TEST (Reference, equal_condition)
{
    int value = 3;
    int new_value = 5;
    sw::Reference<int> ref(value);
    sw::Reference<int> ref2(new_value);

    EXPECT_TRUE(ref.hasValue());
    EXPECT_EQ(*ref, 3);
    EXPECT_EQ(*ref2, 5);
    EXPECT_FALSE(ref == ref2);
    ref2 = value;
    EXPECT_TRUE(ref == ref2);
    EXPECT_TRUE(ref == 3);
}