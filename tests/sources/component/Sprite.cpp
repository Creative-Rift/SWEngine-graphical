/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Sprite.cpp
** Description: [CHANGE]
*/

#include <filesystem>

#include "SW/Engine.hpp"
#include "components/Sprite.hpp"
#include "components/Transform.hpp"

#include "fixture/SpriteFixture.hpp"

TEST_F(SpriteFixture, init)
{
    auto& entity = sw::Engine::getScene("Main").createEntity("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
}

TEST_F(SpriteFixture, entity)
{
    auto& entity = sw::Engine::getScene("Main").createEntity("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");


    ASSERT_EQ(sprite.entity().name(), "test");
}

TEST_F(SpriteFixture, texture)
{
    auto& entity = sw::Engine::getScene("Main").createEntity("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    auto& texture = sw::OpenResources::m_ntext["MissingTexture"];

    ASSERT_EQ(sprite.texture(), texture);
}

TEST_F(SpriteFixture, invert)
{
    auto& entity = sw::Engine::getScene("Main").createEntity("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");

    sprite.invertX(true);
    ASSERT_EQ(sprite.isInvertX(), true);
    sprite.invertY(true);
    ASSERT_EQ(sprite.isInvertY(), true);
    sprite.invertY(false);
    sprite.invertX(false);
    ASSERT_EQ(sprite.isInvertY(), false);
    ASSERT_EQ(sprite.isInvertX(), false);
}