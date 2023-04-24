/*
** EPITECH PROJECT, 2021
** Software Engine Project
** File description:
** Component_Test.cpp
*/

#include "GameObject.hpp"

#include "BaseEngineTest.hpp"

TEST_F (BaseEngineTest, Construction)
{
    TestComponent component = TestComponent(m_gameObject.value());

    //EXPECT_EQ   ( component.gameObject(), testGameObject ); // TODO check the test
    EXPECT_TRUE ( component.isActive() );
}

TEST_F (BaseEngineTest, setActive)
{
    TestComponent component = TestComponent(m_gameObject.value());

    EXPECT_NO_THROW ( component.setActive(true)  );
    EXPECT_TRUE     ( component.isActive()       );
    EXPECT_NO_THROW ( component.setActive(false) );
    EXPECT_FALSE    ( component.isActive()       );
    EXPECT_NO_THROW ( component.setActive(false) );
    EXPECT_FALSE    ( component.isActive()       );
    EXPECT_NO_THROW ( component.setActive(true)  );
    EXPECT_TRUE     ( component.isActive()       );
}