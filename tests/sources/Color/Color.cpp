/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: file.cpp
** Description: [CHANGE]
*/

#include "gtest/gtest.h"

#include "utils/Color.hpp"

TEST(Color, constructor)
{
    sw::Color basic;

    EXPECT_EQ(basic.r, 0);
    EXPECT_EQ(basic.g, 0);
    EXPECT_EQ(basic.b, 0);
    EXPECT_EQ(basic.a, 255);
}

TEST(Color, constructor_with_value)
{
    sw::Color value(1, 2, 3, 6);

    EXPECT_EQ(value.r, 1);
    EXPECT_EQ(value.g, 2);
    EXPECT_EQ(value.b, 3);
    EXPECT_EQ(value.a, 6);
}

TEST(Color, black_color)
{
    EXPECT_EQ(sw::BlackColor.r, 0);
    EXPECT_EQ(sw::BlackColor.g, 0);
    EXPECT_EQ(sw::BlackColor.b, 0);
    EXPECT_EQ(sw::BlackColor.a, 255);
}

TEST(Color, white_color)
{
    EXPECT_EQ(sw::WhiteColor.r, 255);
    EXPECT_EQ(sw::WhiteColor.g, 255);
    EXPECT_EQ(sw::WhiteColor.b, 255);
    EXPECT_EQ(sw::WhiteColor.a, 255);
}

TEST(Color, red_color)
{
    EXPECT_EQ(sw::RedColor.r, 255);
    EXPECT_EQ(sw::RedColor.g, 0);
    EXPECT_EQ(sw::RedColor.b, 0);
    EXPECT_EQ(sw::RedColor.a, 255);
}

TEST(Color, green_color)
{
    EXPECT_EQ(sw::GreenColor.r, 0);
    EXPECT_EQ(sw::GreenColor.g, 255);
    EXPECT_EQ(sw::GreenColor.b, 0);
    EXPECT_EQ(sw::GreenColor.a, 255);
}

TEST(Color, blue_color)
{
    EXPECT_EQ(sw::BlueColor.r, 0);
    EXPECT_EQ(sw::BlueColor.g, 0);
    EXPECT_EQ(sw::BlueColor.b, 255);
    EXPECT_EQ(sw::BlueColor.a, 255);
}

TEST(Color, yellow_color)
{
    EXPECT_EQ(sw::YellowColor.r, 255);
    EXPECT_EQ(sw::YellowColor.g, 255);
    EXPECT_EQ(sw::YellowColor.b, 0);
    EXPECT_EQ(sw::YellowColor.a, 255);
}

TEST(Color, magenta_color)
{
    EXPECT_EQ(sw::MagentaColor.r, 255);
    EXPECT_EQ(sw::MagentaColor.g, 0);
    EXPECT_EQ(sw::MagentaColor.b, 255);
    EXPECT_EQ(sw::MagentaColor.a, 255);
}

TEST(Color, cyan_color)
{
    EXPECT_EQ(sw::CyanColor.r, 0);
    EXPECT_EQ(sw::CyanColor.g, 255);
    EXPECT_EQ(sw::CyanColor.b, 255);
    EXPECT_EQ(sw::CyanColor.a, 255);
}

TEST(Color, transparent_color)
{
    EXPECT_EQ(sw::TransparentColor.r, 0);
    EXPECT_EQ(sw::TransparentColor.g, 0);
    EXPECT_EQ(sw::TransparentColor.b, 0);
    EXPECT_EQ(sw::TransparentColor.a, 0);
}