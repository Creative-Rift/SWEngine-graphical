/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Sprite.cpp
** Description: [CHANGE]
*/

#include <filesystem>

#include "OpenGLModule.hpp"
#include "components/Sprite.hpp"
#include "components/Transform.hpp"
#include "GameObject.hpp"

#include "fixture/SpriteFixture.hpp"

TEST_F(SpriteFixture, init)
{
    sw::ConcreteComponent auto& sprite = m_gameObject.value().createComponent<sw::Sprite>("SpriteManager");

    ASSERT_EQ(sprite.gameObject().name(), m_gameObject.value().name());
}

TEST_F(SpriteFixture, entity)
{
    sw::ConcreteComponent auto& sprite = m_gameObject.value().createComponent<sw::Sprite>("SpriteManager");

    ASSERT_EQ(sprite.gameObject().name(), m_gameObject.value().name());
}

TEST_F(SpriteFixture, texture)
{
    sw::ConcreteComponent auto& sprite = m_gameObject.value().createComponent<sw::Sprite>("SpriteManager");
    auto texture = sw::OpenResources::m_ntext["MissingTexture"];

    ASSERT_EQ(sprite.texture(), texture);
}

TEST_F(SpriteFixture, invert)
{
    sw::ConcreteComponent auto& sprite = m_gameObject.value().createComponent<sw::Sprite>("SpriteManager");

    sprite.flipOnX(true);
    ASSERT_EQ(sprite.isFlippedX(), true);
    sprite.flipOnY(true);
    ASSERT_EQ(sprite.isFlippedY(), true);
    sprite.flipOnY(false);
    sprite.flipOnX(false);
    ASSERT_EQ(sprite.isFlippedY(), false);
    ASSERT_EQ(sprite.isFlippedX(), false);
}