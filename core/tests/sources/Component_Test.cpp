/*
** EPITECH PROJECT, 2021
** Software Engine Project
** File description:
** Component_Test.cpp
*/

#include "SW/Entity.hpp"

#include "testHeader.hpp"

TEST_F (ComponentTester, Construction)
{
    TestComponent component = TestComponent(testEntity.value());

    EXPECT_EQ   ( component.entity(), testEntity );
    EXPECT_TRUE ( component.isActive() );
}

TEST_F (ComponentTester, setActive)
{
    TestComponent component = TestComponent(testEntity.value());

    EXPECT_NO_THROW ( component.setActive(true)  );
    EXPECT_TRUE     ( component.isActive()       );
    EXPECT_NO_THROW ( component.setActive(false) );
    EXPECT_FALSE    ( component.isActive()       );
    EXPECT_NO_THROW ( component.setActive(false) );
    EXPECT_FALSE    ( component.isActive()       );
    EXPECT_NO_THROW ( component.setActive(true)  );
    EXPECT_TRUE     ( component.isActive()       );
}

TEST_F (ComponentTester, cout)
{
    TestComponent component = TestComponent(testEntity.value());

    testing::internal::CaptureStdout();
    std::cout << component;
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "Component [TestComponent] of Entity\n");
}