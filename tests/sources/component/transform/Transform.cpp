/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Transform.cpp
** Description: [CHANGE]
*/

#include "gtest/gtest.h"

#include "SW/Scene.hpp"
#include "SW/Engine.hpp"

#include "OpenGLModule.hpp"
#include "scenes/Main.hpp"
#include "components/Transform.hpp"

TEST(Trasnform, move)
{
    sw::Engine::createModule<sw::OpenGLModule>();
    sw::ConcreteScene auto& mainScene = sw::Engine::createScene<Main>("Main");
    sw::Engine::initialize();
    sw::Engine::activeScene().load();
    auto& entity = mainScene.createEntity("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.move(1, 1, 1);

    ASSERT_EQ(transform.getPosition().x, 1);
    ASSERT_EQ(transform.getPosition().y, 1);
    ASSERT_EQ(transform.getPosition().z, 1);
    sw::Engine::terminate();
}

TEST(Trasnform, setPosition)
{
    sw::Engine::createModule<sw::OpenGLModule>();
    sw::ConcreteScene auto& mainScene = sw::Engine::createScene<Main>("Main");
    sw::Engine::initialize();
    sw::Engine::activeScene().load();
    auto& entity = mainScene.createEntity("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.setPosition(10, 8, 7);

    ASSERT_EQ(transform.getPosition().x, 10);
    ASSERT_EQ(transform.getPosition().y, 8);
    ASSERT_EQ(transform.getPosition().z, 7);
    sw::Engine::terminate();
}

TEST(Trasnform, scale)
{
    sw::Engine::createModule<sw::OpenGLModule>();
    sw::ConcreteScene auto& mainScene = sw::Engine::createScene<Main>("Main");
    sw::Engine::initialize();
    sw::Engine::activeScene().load();
    auto& entity = mainScene.createEntity("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.scale(2, 2, 2);

    ASSERT_EQ(transform.getScale().x, 2);
    ASSERT_EQ(transform.getScale().y, 2);
    ASSERT_EQ(transform.getScale().z, 2);
}

TEST(Trasnform, scale_translate_rotate)
{
    sw::Engine::createModule<sw::OpenGLModule>();
    sw::ConcreteScene auto& mainScene = sw::Engine::createScene<Main>("Main");
    sw::Engine::initialize();
    sw::Engine::activeScene().load();
    auto& entity = mainScene.createEntity("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");
    glm::mat4 result;
    glm::mat4 excepted{{2, 0, 0, 0},
                       {0, 9, 0, 0},
                       {0, 0, 2, 0},
                       {10, 2, 7, 1}};

    transform.move(10, 2, 7);
    transform.scale(2, 9, 2);
    result = transform.getMatrix();

    ASSERT_EQ(transform.getPosition().x, 10);
    ASSERT_EQ(transform.getPosition().y, 2);
    ASSERT_EQ(transform.getPosition().z, 7);
    ASSERT_EQ(transform.getScale().x, 2);
    ASSERT_EQ(transform.getScale().y, 9);
    ASSERT_EQ(transform.getScale().z, 2);
    for (int line = 0; line < glm::mat4::length(); line++)
        for (int col = 0; col < result[line].length(); col++) {
            std::cout << line << " " << col << std::endl;
            ASSERT_EQ(result[line][col], excepted[line][col]);
        }
}