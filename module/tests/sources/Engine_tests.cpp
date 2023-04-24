/*
** Society: Rift...
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Engine_tests.cpp
** Description: [CHANGE]
*/

#include "Engine_tests.hpp"

/*
TEST_F (EngineTester, init_normal_end)
{
    ASSERT_NO_THROW(sw::OpenGLModule::load());
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}*/

/*
TEST_F (EngineTester, init_throw)
{
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_initThrow = true);
    ASSERT_ANY_THROW(sw::OpenGLModule::load());
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
    EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_initThrow = false);
}
*/
/*
TEST_F (EngineTester, clear_on_play)
{
    sw::Speech::clearOnPlay = true;
    EXPECT_NO_THROW(sw::OpenGLModule::load());
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}

TEST_F (EngineTester, init_alreadyLoaded_end)
{
    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;

    sw::OpenGLModule::load();
    sw::Speech::clearConsole();
    ASSERT_NO_THROW(sw::OpenGLModule::load());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("ShipWreck Engine is already loaded!"), std::string::npos);
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}


TEST_F (EngineTester, update_throw)
{
    sw::Speech::displayed = true;
    ASSERT_NO_THROW(sw::OpenGLModule::load()); // TODO fix the test
    //EXPECT_NO_THROW(sw::OpenGLModule::update()).m_updateThrow = true);
    //EXPECT_NO_THROW(sw::OpenGLModule::update());
    //EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_updateThrow = false);
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
}*/


TEST_F (EngineTester, update_noLoaded)
{
    sw::Speech::displayed = true;

    sw::OpenGLModule::unload();
    testing::internal::CaptureStdout();
    EXPECT_NO_THROW(sw::OpenGLModule::update());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("ShipWreck Engine cannot perform an update. Plead load the Engine first!"), std::string::npos);
}

/*
TEST_F (EngineTester, unload)
{
    testing::internal::CaptureStdout();
    sw::Speech::displayed = true;

    ASSERT_NO_THROW(sw::OpenGLModule::load());
    sw::Speech::clearConsole();
    EXPECT_NO_THROW(sw::OpenGLModule::unload());
    sw::Speech::flush();
    EXPECT_NE(testing::internal::GetCapturedStdout().find("ShipWreck Engine was successfully unload!"), std::string::npos);
}

TEST_F (EngineTester, end_throw)
{// TODO fix the test
    //EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_endThrow = true);
    ASSERT_NO_THROW(sw::OpenGLModule::load());
    EXPECT_ANY_THROW(sw::OpenGLModule::unload());
    //EXPECT_NO_THROW(dynamic_cast<EngineTestModule&>(sw::OpenGLModule::getModule()).m_endThrow = false);
}
*/

TEST_F (EngineTester, createScene)
{
    sw::OpenGLModule::sceneManager().createScene("EngineTestsScene");

    EXPECT_NO_THROW(EXPECT_STREQ(sw::OpenGLModule::sceneManager().getScene("EngineTestsScene")->name.c_str(), "EngineTestsScene"));
}

TEST_F (EngineTester, get_wrong_scene)
{
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getScene("scene"));
}


TEST_F (EngineTester, get_scene_cast)
{
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().getScene("TestScene"));
}

TEST_F (EngineTester, get_wrong_scene_cast)
{
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getScene("TestsScene"));
}

TEST_F (EngineTester, getActiveScene)
{
    EXPECT_NO_THROW(EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene"));
}

TEST_F (EngineTester, activeScene_wrong)
{
    sw::OpenGLModule::unload();
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getActiveScene());
}

TEST_F (EngineTester, activeScene_no_cast)
{
    EXPECT_NO_THROW(EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene"));
}

TEST_F (EngineTester, activeScene_no_cast_wrong)
{
    sw::OpenGLModule::unload();
    EXPECT_ANY_THROW(sw::OpenGLModule::sceneManager().getActiveScene());
}

/*
TEST_F (EngineTester, deleteScene)
{
    sw::OpenGLModule::load(); // TODO Check feature
    //sw::OpenGLModule::sceneManager().deleteScene("TestScene");
    sw::OpenGLModule::update();
    //EXPECT_FALSE(sw::OpenGLModule::hasScene("TestScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, deleteScene_wrong)
{
    sw::OpenGLModule::load();
    //EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().deleteScene("TestScee"));
    //EXPECT_TRUE(sw::OpenGLModule::hasScene("TestScene"));
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, set_active_scene)
{
    sw::OpenGLModule::load();
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().createScene("EngineTestScene"));
    EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene");
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().loadScene("EngineTestScene"));
    sw::OpenGLModule::update();
    EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "EngineTestScene");
    sw::OpenGLModule::unload();
}

TEST_F (EngineTester, set_active_wrong_scene)
{
    sw::OpenGLModule::load();
    EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene");
    EXPECT_NO_THROW(sw::OpenGLModule::sceneManager().loadScene("EngineTestSne"));
    EXPECT_STREQ(sw::OpenGLModule::sceneManager().getActiveScene()->name.c_str(), "TestScene");
    sw::OpenGLModule::unload();
}*/