/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** testHeader.hpp
*/

#ifndef __UNITESTS_TESTHEADER_HPP__
#define __UNITESTS_TESTHEADER_HPP__

#include <gtest/gtest.h>

#include "resources/AResources.hpp"
#include "OpenGLModule.hpp"
#include "Managers.hpp"
#include "Reference.hpp"
#include "Scene.hpp"
#include "EventInfo.hpp"
#include "SceneLoadEvent.hpp"

class TestComponent : public sw::Component
{
    public:
        using sw::Component::Component;
        ~TestComponent() = default;
};

class TestCptManager : public sw::AManager<TestComponent>
{
public:
    using sw::AManager<TestComponent>::AManager;
    ~TestCptManager() = default;

    void onUpdate() override {}
};

class TestScene
{
    public:
        ~TestScene() = default;

        std::string name() {return ("ye");}

        void onLoad(sw::EventInfo& info)
        {
            auto& scene = info.getInfo<sw::SceneLoadEvent>().scene;

            if (scene.name != "TestScene")
                return;

            scene.createManager<TestCptManager>("CptManager");
        }
};

class BaseEngineTest : public testing::Test
{
    protected:
        sw::Reference<sw::GameObject> m_gameObject;
        sw::Reference<sw::Scene> m_scene;
        TestScene *m_testScene;

        void baseSetUp() {
            m_testScene = new TestScene;
            // Create Scene
            sw::OpenGLModule::sceneManager().createScene("TestScene");
            sw::OpenGLModule::eventManager().create("SceneLoad");
            sw::OpenGLModule::eventManager()["SceneLoad"].subscribe("TestScene", m_testScene, &TestScene::onLoad);

            //sw::OpenGLModule::load();
            sw::OpenGLModule::sceneManager().loadScene("TestScene");
            m_scene.emplace(*sw::OpenGLModule::sceneManager().getScene("TestScene"));
            m_gameObject.emplace(m_scene.value().createGameObject("GameObjectTest"));
            sw::Speech::flush();
        }

        void baseTearDown()
        {
            sw::OpenGLModule::unload();
            sw::Speech::flush();
            delete m_testScene;
        }

        virtual void SetUp() override {
            std::cout << "SetUp" << std::endl;
            baseSetUp();
        }
        virtual void TearDown() override {
            std::cout << "TearDown" << std::endl;
            baseTearDown();
        }
};

#endif // __UNITESTS_TESTHEADER_HPP__