/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Engine_tests.hpp
** Description: [CHANGE]
*/

#ifndef __UNITESTS_ENGINE_TESTS_HPP__
#define __UNITESTS_ENGINE_TESTS_HPP__

#include <gtest/gtest.h>

#include "SW/Engine.hpp"
#include "SW/utils/Speech.hpp"

class EngineTestResources
        :   public sw::AResources
{
public:
    void loadResources() override {}
    void unloadResources() override {}
    void addNeededResource(const std::string& name, const std::string& path, const std::string& type) override {};
};

class EngineTestScene
        :   public sw::AScene
{
public:
    using sw::AScene::AScene;
    ~EngineTestScene() {}

    void onLoad() override {}
    void onUpdate() override {}
    void onUnload() override {}
    std::string type() const override { return ("EngineTestScene"); }
};

class EngineTestModule
        :   public sw::AModule
{
public:
    using sw::AModule::AModule;
    ~EngineTestModule() {}
    bool m_ok = true;
    bool m_initThrow = false;
    bool m_updateThrow = false;
    bool m_endThrow = false;

    void initialize() override {
        if (m_initThrow)
            throw sw::Error("Throw on initialization", "Code");
        sw::Engine::createScene<EngineTestScene>("TestScene");
    }
    void update() override
    {
        static int i = 0;

        if (m_updateThrow)
            throw sw::Error("Throw on update", "Code");
        if (i == 1)
            m_ok = false;
        i++;
    }
    void terminate() override { if (m_endThrow) throw sw::Error("Throw on terminate", "Code"); }
    bool isOk() override { return (m_ok); }
    std::unique_ptr<sw::AResources> createResourceInstance() override {
        return (std::make_unique<EngineTestResources>());
    }
    std::string type() const override { return ("EngineTestModule"); }
    void loadResourcesFile(const std::string& path) override {};
};

class EngineTester
        :   public testing::Test
{
protected:
    virtual void SetUp()
    {
        sw::Speech::displayed = false;
        sw::Engine::createModule<EngineTestModule>();
        sw::Engine::initialize();
    }

    virtual void TearDown()
    {
        sw::Speech::displayed = true;
        sw::Engine::terminate();
    }
};

#endif // __UNITESTS_ENGINE_TESTS_HPP__
