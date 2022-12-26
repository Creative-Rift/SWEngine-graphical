/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Animator.cpp
** Description: [CHANGE]
*/

#include <filesystem>

#include "OpenGLModule.hpp"
#include "components/Sprite.hpp"
#include "components/Animator.hpp"
#include "components/Transform.hpp"

#include "fixture/AnimatorFixture.hpp"

TEST_F(AnimatorFixture, init)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = entity.createComponent<sw::Animator>("AnimatorManager");
}

TEST_F(AnimatorFixture, displayRect)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = entity.createComponent<sw::Animator>("AnimatorManager");

    animator.setRect({10, 10});
    ASSERT_EQ(animator.getRect().x, 10);
    ASSERT_EQ(animator.getRect().y, 10);
}

TEST_F(AnimatorFixture, loop)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = entity.createComponent<sw::Animator>("AnimatorManager");

    animator.setLoop(true, 10);
    ASSERT_EQ(animator.isLoop(), true);
    ASSERT_EQ(animator.getLoopDelay(), 10);
}

TEST_F(AnimatorFixture, animation_speed)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = entity.createComponent<sw::Animator>("AnimatorManager");

    animator.setFPS(10);
    ASSERT_EQ(animator.getFPS(), 10);
}

TEST_F(AnimatorFixture, animation_type)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = entity.createComponent<sw::Animator>("AnimatorManager");

    animator.setAnimType(sw::Animator::ANIM_LINE);
    ASSERT_EQ(animator.getAnimType(), sw::Animator::ANIM_LINE);
    animator.setAnimType(sw::Animator::ANIM_SPRITE);
    ASSERT_EQ(animator.getAnimType(), sw::Animator::ANIM_SPRITE);
}

TEST_F(AnimatorFixture, animation_play)
{
    auto& entity = sw::OpenGLModule::sceneManager().getScene("Main")->createGameObject("test");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = entity.createComponent<sw::Animator>("AnimatorManager");

    ASSERT_EQ(animator.isPlaying(), false);
    animator.play();
    ASSERT_EQ(animator.isPlaying(), true);
    animator.pause();
    ASSERT_EQ(animator.isPlaying(), false);
}