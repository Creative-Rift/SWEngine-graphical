/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Event_Tests.cpp
*/

#include "EventTester.hpp"
#include "SW/Event.hpp"

TEST_F (EventTester, test)
{
    sw::EventManager manager;

    EXPECT_NO_THROW(manager.create("An event"));
    EXPECT_NO_THROW(manager.create("An event"));

    EXPECT_TRUE(manager.hasEvent("An event"));
    EXPECT_FALSE(manager.hasEvent("Inexistant event"));

    EXPECT_NO_THROW(manager.get("An event"));
    EXPECT_ANY_THROW(manager.get("Inexistant event"));

    EXPECT_NO_THROW(manager["An event"]);
    EXPECT_ANY_THROW(manager["Inexistant event"]);
}