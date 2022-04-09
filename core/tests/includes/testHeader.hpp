/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** testHeader.hpp
*/

#ifndef __UNITESTS_TESTHEADER_HPP__
#define __UNITESTS_TESTHEADER_HPP__

#include <gtest/gtest.h>

#include "SW/Resources.hpp"
#include "SW/Module.hpp"
#include "SW/Engine.hpp"
#include "SW/Manager.hpp"
#include "Reference.hpp"

class TestResources
    :   public sw::AResources
{
    public:
        void loadResources() override {}
        void unloadResources() override {}
        void addNeededResource(const std::string& name, const std::string& path, const std::string& type) override {};
};

class TestModule
    :   public sw::AModule
{
    public:
        using sw::AModule::AModule;
        ~TestModule() = default;

        void initialize() override
        {
            sw::Engine::activeScene().load();
        }
        void update() override {}
        void terminate() override {}
        bool isOk() override { return (true); }
        std::unique_ptr<sw::AResources> createResourceInstance() override {
            return (std::make_unique<TestResources>());
        }
        std::string type() const override { return ("TestModule"); }
        void loadResourcesFile(const std::string& path) override {};
};

class TestComponent
    :   public sw::Component
{
    public:
        using sw::Component::Component;
        ~TestComponent() = default;

        std::string type() const override { return ("TestComponent"); }
};

class TestCptManager
        :   public sw::AManager<TestComponent>
{
public:
    using sw::AManager<TestComponent>::AManager;
    ~TestCptManager() = default;

    void onUpdate() override {}
    std::string type() const override { return ("TestCptManager"); }
};

class TestScene
    :   public sw::AScene
{
    public:
        using sw::AScene::AScene;
        ~TestScene() = default;

        void onLoad() override
        {
            createManager<TestCptManager>("CptManager");
        }
        void onUpdate() override {}
        void onUnload() override {}
    std::string type() const override { return ("TestScene"); }
};

class ComponentTester
    :   public testing::Test
{
    protected:
        sw::Reference<TestScene> testScene;
        sw::Reference<sw::Entity> testEntity;

        void SetUp() override {
            sw::Engine::createModule<TestModule>();
            testScene = sw::Engine::createScene<TestScene>("TestScene");
            sw::Engine::initialize();
            testEntity = testScene.value().createEntity("Entity");
        }
        void TearDown() override {
            sw::Engine::terminate();
        }
};

class EntityTester
    :   public ComponentTester
{
    protected:
        void SetUp() override {
            sw::Engine::createModule<TestModule>();
            testScene = sw::Engine::createScene<TestScene>("TestScene");
            sw::Engine::initialize();
        }
        void TearDown() override {
            sw::Engine::terminate();
        }
};

#endif // __UNITESTS_TESTHEADER_HPP__