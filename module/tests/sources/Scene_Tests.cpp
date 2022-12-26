/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Scene_Tests.cpp
** Description: [CHANGE]
*/

#include "SceneTester.hpp"
// TODO Fix all comment
TEST_F (SceneTester, hasGameObject)
{
    EXPECT_TRUE(sw::OpenGLModule::sceneManager().getActiveScene()->hasGameObject("Entity"));
    EXPECT_FALSE(sw::OpenGLModule::sceneManager().getActiveScene()->hasGameObject("Enti"));
}

TEST_F (SceneTester, deleteRequested)
{
    sw::OpenGLModule::sceneManager().getActiveScene()->deleteGameObject("Entity");
    sw::OpenGLModule::sceneManager().getActiveScene()->update();
    EXPECT_FALSE(sw::OpenGLModule::sceneManager().getActiveScene()->hasGameObject("Entity"));
}

TEST_F (SceneTester, already_load)
{
    sw::Speech::displayed = true;
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().getActiveScene()->load());
    sw::Speech::flush();
    std::string str = testing::internal::GetCapturedStdout();
    EXPECT_NE(str.find("- TestScene - was already loaded !"), std::string::npos);
}

TEST_F (SceneTester, update_once)
{
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().getActiveScene()->update());
}

TEST_F (SceneTester, update_not_loaded)
{
    sw::Speech::displayed = true;
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().getActiveScene()->unload());
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().getActiveScene()->update());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("- TestScene - can not be updated because it was not loaded."), std::string::npos);
}

TEST_F (SceneTester, scene_init_throw)
{
    //EXPECT_NO_THROW(sw::OpenGLModule::createScene<TestThrowScene>("Throw"));
    //sw::OpenGLModule::getScene<TestThrowScene>("Throw").m_init = true;
    //EXPECT_ANY_THROW(sw::OpenGLModule::getScene<TestThrowScene>("Throw").load());
    //sw::OpenGLModule::getScene<TestThrowScene>("Throw").m_init = false;
}

TEST_F (SceneTester, scene_update_throw)
{
    //EXPECT_NO_THROW(sw::OpenGLModule::createScene<TestThrowScene>("Throw"));
    //EXPECT_NO_THROW(sw::OpenGLModule::getScene<TestThrowScene>("Throw").load());
    //sw::OpenGLModule::getScene<TestThrowScene>("Throw").m_update = true;
    //EXPECT_ANY_THROW(sw::OpenGLModule::getScene<TestThrowScene>("Throw").update());
    //sw::OpenGLModule::getScene<TestThrowScene>("Throw").m_update = false;
}

TEST_F (SceneTester, scene_update_manager_throw)
{
    //EXPECT_NO_THROW(sw::OpenGLModule::createScene<TestThrowScene>("Throw"));
    //sw::OpenGLModule::getScene<TestThrowScene>("Throw").m_manager = true;
    //EXPECT_NO_THROW(sw::OpenGLModule::getScene<TestThrowScene>("Throw").load());
    //testing::internal::CaptureStdout();
    //EXPECT_NO_THROW(sw::OpenGLModule::getScene<TestThrowScene>("Throw").update());
    //sw::Speech::displayed = true;
    //sw::Speech::flush();
    //std::string str = testing::internal::GetCapturedStdout();
    //EXPECT_NE(str.find("TestCptManagerThrow"), std::string::npos);
    //sw::OpenGLModule::getScene<TestThrowScene>("Throw").m_manager = false;
}

TEST_F (SceneTester, scene_terminate_throw)
{
    //EXPECT_NO_THROW(sw::OpenGLModule::createScene<TestThrowScene>("Throw"));
    //EXPECT_NO_THROW(sw::OpenGLModule::getScene<TestThrowScene>("Throw").load());
    //sw::OpenGLModule::getScene<TestThrowScene>("Throw").m_term = true;
    //EXPECT_ANY_THROW(sw::OpenGLModule::getScene<TestThrowScene>("Throw").unload());
    //sw::OpenGLModule::getScene<TestThrowScene>("Throw").m_term = false;
}

TEST_F (SceneTester, has_facrtory)
{
    EXPECT_TRUE(sw::OpenGLModule::sceneManager().getActiveScene()->hasManager("CptManager"));
    EXPECT_FALSE(sw::OpenGLModule::sceneManager().getActiveScene()->hasManager("TestCpt"));
}

TEST_F (SceneTester, delete_manager)
{
    sw::OpenGLModule::sceneManager().getActiveScene()->createManager<TestCptManager>("test");
    EXPECT_TRUE(sw::OpenGLModule::sceneManager().getActiveScene()->hasManager("test"));
    sw::OpenGLModule::sceneManager().getActiveScene()->deleteManager("test");
    sw::OpenGLModule::sceneManager().getActiveScene()->update();
    EXPECT_FALSE(sw::OpenGLModule::sceneManager().getActiveScene()->hasManager("test"));
}

TEST_F (SceneTester, set_layer_manager)
{
    //sw::OpenGLModule::sceneManager().getActiveScene()->createManager<TestCptManager>("test");
    //EXPECT_TRUE(sw::OpenGLModule::sceneManager().getActiveScene()->hasManager("test"));
    //sw::OpenGLModule::sceneManager().getActiveScene()->setLayer("test", 123);
    //EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().getActiveScene()->setLayer("CManager", 1));
    //EXPECT_EQ(sw::OpenGLModule::sceneManager().getActiveScene()->getLayer("test"), 123);
    //EXPECT_EQ(sw::OpenGLModule::sceneManager().getActiveScene()->getLayer("CptManager"), 0);
}

TEST_F (SceneTester, get_layer_manager)
{
    //EXPECT_EQ(sw::OpenGLModule::sceneManager().getActiveScene()->getLayer("CptManager"), 0);
    //EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getActiveScene()->getLayer("CManager"));
}