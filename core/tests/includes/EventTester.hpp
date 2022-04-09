/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** EventTester.hpp
*/

#ifndef __UNITESTS_EVENTTESTER_HPP__
#define __UNITESTS_EVENTTESTER_HPP__

#include <gtest/gtest.h>
#include "SW/Engine.hpp"
#include "SW/Scene.hpp"
#include "SW/Manager.hpp"
#include "SW/Component.hpp"
#include "Engine_tests.hpp"

class Scene
    :   public sw::AScene
{
    public:
        using sw::AScene::AScene;
        void onLoad() override {}
        void onUpdate() override {}
        void onUnload() override {}
        std::string type() const override { return ("Scene"); }
};

class Manager
    :   public sw::ScriptManager
{
    public:
        using sw::ScriptManager::ScriptManager;
        ~Manager() override = default;
        void onUpdate() override {};
        std::string type() const override { return ("Manager"); }
};

class Script
    :   public sw::Component
{
    public:
        using sw::Component::Component;
        void helloWorld()
        {
            std::cout << "Hello World !" << std::endl;
        }
        std::string type() const override { return ("Script"); }
};

class EventTester
    :   public testing::Test
{
    public:
        virtual void SetUp() {
            sw::Engine::createModule<EngineTestModule>();
            auto& scene = sw::Engine::createScene<Scene>("SceneTest");
            auto& fact = scene.createManager<Manager>("ScriptManager");
            scene.createEntity("Entity");
            fact.createComponent<Script>("Entity");
            sw::Engine::initialize();
        }

        virtual void TearDown() {
            sw::Engine::deleteScene("SceneTest");
            sw::Engine::terminate();
        }
};

#endif // __UNITESTS_EVENTTESTER_HPP__