/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Chrono_Tests.cpp
** Description: [CHANGE]
*/

#include <gtest/gtest.h>
#include <thread>

#include "SW/Utils.hpp"

TEST (Chrono, constructor)
{
    sw::Chrono chrono;

    EXPECT_FALSE(chrono.isRunning());
}

TEST (Chrono, constructor_start)
{
    sw::Chrono chrono(sw::Chrono::Lauch);

    EXPECT_TRUE(chrono.isRunning());
}

TEST (Chrono, constructor_Wait)
{
    sw::Chrono chrono(sw::Chrono::Wait);

    EXPECT_FALSE(chrono.isRunning());
}

TEST (Chrono, start_stop)
{
    sw::Chrono chrono;

    chrono.start();
    chrono.stop();
    EXPECT_FALSE(chrono.isRunning());
}

TEST (Chrono, total_time)
{
    sw::Chrono chrono;

    chrono.start();
    ASSERT_TRUE(chrono.isRunning());
    std::this_thread::sleep_for(std::chrono::milliseconds (1));
    EXPECT_GE(chrono.getTotalTime(), 0.001);
}

TEST (Chrono, elapsed_time)
{
    sw::Chrono chrono;

    chrono.start();
    ASSERT_TRUE(chrono.isRunning());
    std::this_thread::sleep_for(std::chrono::milliseconds (1));
    chrono.tour();
    std::this_thread::sleep_for(std::chrono::milliseconds (1));
    EXPECT_GE(chrono.getElapsedTime(), 0.001);
}