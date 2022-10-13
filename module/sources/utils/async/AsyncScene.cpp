/*
** ShipWreck Engine , 2022
** AsyncScene.cpp
*/

#include <utility>

#include "AsyncScene.hpp"
#include "OpenGLModule.hpp"
#include "Window.hpp"

sw::AsyncScene::AsyncScene() :
sw::AsyncOperation(),
m_sceneName(),
m_done(false),
m_scene(nullptr)
{}

sw::AsyncScene::AsyncScene(std::string sceneName) :
AsyncOperation(),
m_sceneName(std::move(sceneName)),
m_done(false),
m_scene(sw::OpenGLModule::sceneManager().getScene(m_sceneName))
{
    m_thread = std::make_shared<std::thread>(startThread, this);
}

sw::AsyncScene::~AsyncScene() noexcept
= default;

void sw::startThread(sw::AsyncScene *asyncScene)
{
    asyncScene->m_scene->load(true);
    asyncScene->m_done = true;
}

bool sw::AsyncScene::isDone()
{
    return (m_done);
}