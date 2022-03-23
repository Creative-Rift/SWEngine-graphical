/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Transform.cpp
** Description: [CHANGE]
*/

#include "SW/Engine.hpp"

#include "OpenGLModule.hpp"

#include "scenes/Main.hpp"
#include "fixture/SpriteFixture.hpp"

void SpriteFixture::SetUp()
{
    sw::Engine::createModule<sw::OpenGLModule>();
    sw::ConcreteScene auto& mainScene = sw::Engine::createScene<Main>("Main");
    sw::Engine::initialize();
    sw::Engine::activeScene().load();
}

void SpriteFixture::TearDown()
{
    sw::Engine::terminate();
}