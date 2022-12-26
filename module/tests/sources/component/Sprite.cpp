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
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
}

TEST_F(SpriteFixture, entity)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");


    ASSERT_EQ(sprite.gameObject().name(), "test");
}

TEST_F(SpriteFixture, texture)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    auto texture = sw::OpenResources::m_ntext["MissingTexture"];

    ASSERT_EQ(sprite.texture(), texture);
}

TEST_F(SpriteFixture, invert)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");

    sprite.flipOnX(true);
    ASSERT_EQ(sprite.isFlippedX(), true);
    sprite.flipOnY(true);
    ASSERT_EQ(sprite.isFlippedY(), true);
    sprite.flipOnY(false);
    sprite.flipOnX(false);
    ASSERT_EQ(sprite.isFlippedY(), false);
    ASSERT_EQ(sprite.isFlippedX(), false);
}