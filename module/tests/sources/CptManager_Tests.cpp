/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: CptManager_Tests.cpp
** Description: [CHANGE]
*/

#include "GameObject.hpp"
#include "OpenGLModule.hpp"

#include "CptManager_Tests.hpp"

TEST_F (CptManagerTester, contructor)
{
    sw::OpenGLModule::sceneManager().getActiveScene()->createManager<TestCptManager>("CptManager");
    auto& module = sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManager>("CptManager");

    EXPECT_STREQ(module.name().c_str(), "CptManager");
}

TEST_F (CptManagerTester, load)
{
    sw::OpenGLModule::sceneManager().getActiveScene()->createManager<TestCptManager>("CptManager");
    auto& module = sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManager>("CptManager");

    EXPECT_NO_THROW(module.load());
}

TEST_F (CptManagerTester, load_already)
{
    sw::OpenGLModule::sceneManager().getActiveScene()->createManager<TestCptManager>("CptManager");
    auto& module = sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManager>("CptManager");

    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(module.load());
    EXPECT_NO_THROW(module.load());
    sw::Speech::displayed = true;
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("- CptManager - was already loaded !"), std::string::npos);
}

TEST_F (CptManagerTester, update)
{
    sw::OpenGLModule::sceneManager().getActiveScene()->createManager<TestCptManagerThrow>("ManagerThrow");
    auto& module = sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManagerThrow>("ManagerThrow");

    EXPECT_NO_THROW(module.update());
}

TEST_F (CptManagerTester, update_no_load)
{
    sw::OpenGLModule::sceneManager().getActiveScene()->createManager<TestCptManagerThrow>("ManagerThrow");
    auto& module = sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManagerThrow>("ManagerThrow");

    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;
    EXPECT_NO_THROW(module.update());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("- ManagerThrow - can not be updated because it was not loaded."), std::string::npos);
}

TEST_F (CptManagerTester, unload)
{
    sw::OpenGLModule::sceneManager().getActiveScene()->createManager<TestCptManagerThrow>("ManagerThrow");
    auto& module = sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManagerThrow>("ManagerThrow");

    EXPECT_NO_THROW(module.load());
    EXPECT_NO_THROW(module.unload());
}

TEST_F (CptManagerTester, create_component_no_entity)
{
    auto& manager = sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManager>("CptManager");

    EXPECT_ANY_THROW(manager.createComponent("oui"));
}

TEST_F (CptManagerTester, delete_component)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");
    auto& entity = scene->createGameObject("oui");

    EXPECT_NO_THROW(manager.createComponent("oui"));
    EXPECT_NO_THROW(manager.deleteComponent("oui"));
    manager.update();
    EXPECT_ANY_THROW(entity.getComponent<sw::Component>("CptManager"));
}

TEST_F (CptManagerTester, delete_component_no_entity)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");

    EXPECT_NO_THROW(manager.deleteComponent("oui"));
}

TEST_F (CptManagerTester, setLayer)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");
    auto& entity = scene->createGameObject("oui");

    manager.createComponent("oui");
    EXPECT_NO_THROW(manager.setLayer("oui", 1));
    EXPECT_EQ(manager.getLayer("oui"), 1);
}

TEST_F (CptManagerTester, setLayer_no_entity)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");

    EXPECT_ANY_THROW(int layer = manager.getLayer("oui"));
}

TEST_F (CptManagerTester, get_component_no_entity)
{
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManager>("CptManager")["oui"]);
}

TEST_F (CptManagerTester, has_component_no_entity)
{
    EXPECT_FALSE(sw::OpenGLModule::sceneManager().getActiveScene()->getManager<TestCptManager>("CptManager").hasComponent("oui"));
}

TEST_F (CptManagerTester, has_component)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");
    auto& entity = scene->createGameObject("oui");

    manager.createComponent("oui");
    EXPECT_TRUE(manager.hasComponent("oui"));
}

TEST_F (CptManagerTester, has_no_component)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");
    auto& entity = scene->createGameObject("oui");

    EXPECT_FALSE(manager.hasComponent("oui"));
}

TEST_F (CptManagerTester, name)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");

    EXPECT_STREQ(manager.name().c_str(), "CptManager");
}

TEST_F (CptManagerTester, scene)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");

    EXPECT_STREQ(manager.scene().name.c_str(), "TestScene");
}

TEST_F (CptManagerTester, is_active)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");

    EXPECT_TRUE(manager.isActive());
    manager.setActive(false);
    EXPECT_FALSE(manager.isActive());
}

TEST_F (CptManagerTester, cout)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");
    auto& entity = scene->createGameObject("oui");

    testing::internal::CaptureStdout();
    manager.createComponent("oui");
    //std::cout << manager; // TODO check if the test is usefully
    EXPECT_STREQ(testing::internal::GetCapturedStdout().c_str(), "Manager 'CptManager'\n\tType : 'TestCptManager'\n\tIs Load : true\n\tIs Active : true\n\nComponents count : 1\n");
}

TEST_F (CptManagerTester, begin)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");

    EXPECT_NO_THROW(manager.begin());
}

TEST_F (CptManagerTester, end)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");

    EXPECT_NO_THROW(manager.end());
}

TEST_F (CptManagerTester, add_script)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");
    auto& entity = scene->createGameObject("oui");

    EXPECT_NO_THROW(manager.createComponent<TestComponent>("oui"));
    EXPECT_TRUE(manager.hasComponent("oui"));
}

TEST_F (CptManagerTester, add_script_no_entity)
{
    auto scene = sw::OpenGLModule::sceneManager().getActiveScene();
    auto& manager = scene->getManager<TestCptManager>("CptManager");

    EXPECT_ANY_THROW(manager.createComponent<TestComponent>("oui"));
    EXPECT_FALSE(manager.hasComponent("oui"));
}