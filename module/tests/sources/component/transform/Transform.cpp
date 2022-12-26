/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Transform.cpp
** Description: [CHANGE]
*/

#include "OpenGLModule.hpp"

#include "components/Transform.hpp"
#include "GameObject.hpp"

#include "fixture/TransformTest.hpp"

TEST_F(TransformTest, move_value)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.move(1, 1, 1);

    ASSERT_EQ(transform.getPosition().x, 1);
    ASSERT_EQ(transform.getPosition().y, 1);
    ASSERT_EQ(transform.getPosition().z, 1);
}

TEST_F(TransformTest, move_vector)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.move({10, 8, 789});

    ASSERT_EQ(transform.getPosition().x, 10);
    ASSERT_EQ(transform.getPosition().y, 8);
    ASSERT_EQ(transform.getPosition().z, 789);
}

TEST_F(TransformTest, setPosition_value)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.setPosition(10, 8, 7);

    ASSERT_EQ(transform.getPosition().x, 10);
    ASSERT_EQ(transform.getPosition().y, 8);
    ASSERT_EQ(transform.getPosition().z, 7);
}

TEST_F(TransformTest, setPosition_vector)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.setPosition({10, 8, 7});

    ASSERT_EQ(transform.getPosition().x, 10);
    ASSERT_EQ(transform.getPosition().y, 8);
    ASSERT_EQ(transform.getPosition().z, 7);
}

TEST_F(TransformTest, scale_value)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.scale(2, 2, 2);
    transform.scale(2, 2, 2);

    ASSERT_EQ(transform.getScale().x, 4);
    ASSERT_EQ(transform.getScale().y, 4);
    ASSERT_EQ(transform.getScale().z, 4);
}

TEST_F(TransformTest, scale_vector)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.scale({2, 2, 2});
    transform.scale({20, 20, 20});

    ASSERT_EQ(transform.getScale().x, 40);
    ASSERT_EQ(transform.getScale().y, 40);
    ASSERT_EQ(transform.getScale().z, 40);
}

TEST_F(TransformTest, setScale_value)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.setScale(2, 2, 2);
    transform.setScale(20, 20, 20);

    ASSERT_EQ(transform.getScale().x, 20);
    ASSERT_EQ(transform.getScale().y, 20);
    ASSERT_EQ(transform.getScale().z, 20);
}

TEST_F(TransformTest, setScale_vector)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& transform = entity.createComponent<sw::Transform>("TransformManager");

    transform.setScale({2, 2, 2});
    transform.setScale({80, 80, 80});

    ASSERT_EQ(transform.getScale().x, 80);
    ASSERT_EQ(transform.getScale().y, 80);
    ASSERT_EQ(transform.getScale().z, 80);
}

TEST_F(TransformTest, scale_translate_rotate)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
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
        for (int col = 0; col < result[line].length(); col++)
            ASSERT_EQ(result[line][col], excepted[line][col]);
}